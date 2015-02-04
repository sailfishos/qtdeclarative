/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <qtest.h>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QDebug>
#include <QStringListModel>
#include "../../shared/util.h"
#include "testtypes.h"
#include "qtestmodel.h"

#define INIT_TEST_OBJECT(fileName, object) \
    QQmlComponent component_##object(&engine, testFileUrl(fileName)); \
    QScopedPointer<ItemModelsTest>object(qobject_cast<ItemModelsTest *>(component_##object.create())); \


class tst_qqmlitemmodels : public QQmlDataTest
{
    Q_OBJECT

public:
    tst_qqmlitemmodels() {}

private slots:
    void initTestCase();

    void modelIndex();
    void persistentModelIndex();
    void modelIndexConversion();
    void itemSelectionRange();
    void itemSelection();
    void modelIndexList();

private:
    QQmlEngine engine;
};

void tst_qqmlitemmodels::initTestCase()
{
    QQmlDataTest::initTestCase();
    qmlRegisterType<ItemModelsTest>("Test", 1, 0, "ItemModelsTest");
}

void tst_qqmlitemmodels::modelIndex()
{
    INIT_TEST_OBJECT("modelindex.qml", object);
    TestModel model(10, 10);

    QModelIndex index = object->modelIndex();
    for (int i = 0; i < 5; i++) {
        QCOMPARE(object->property("isValid").toBool(), index.isValid());
        QCOMPARE(object->property("row").toInt(), index.row());
        QCOMPARE(object->property("column").toInt(), index.column());
        QCOMPARE(object->property("parent").toModelIndex(), index.parent());
        QCOMPARE(object->property("model").value<QAbstractItemModel *>(), index.model());
        QCOMPARE(object->property("internalId").toULongLong(), index.internalId());

        if (i < 3) {
            index = model.index(2 + i, 4 - i, index);
            object->setModelIndex(index);
        } else if (i < 4) {
            index = model.index(2 + i, 4 - i);
            object->emitSignalWithModelIndex(index);
        }
    }
}

void tst_qqmlitemmodels::persistentModelIndex()
{
    INIT_TEST_OBJECT("persistentmodelindex.qml", object);
    TestModel model(10, 10);

    QPersistentModelIndex index = object->persistentModelIndex();
    for (int i = 0; i < 5; i++) {
        QCOMPARE(object->property("isValid").toBool(), index.isValid());
        QCOMPARE(object->property("row").toInt(), index.row());
        QCOMPARE(object->property("column").toInt(), index.column());
        QCOMPARE(object->property("parent").toModelIndex(), index.parent());
        QCOMPARE(object->property("model").value<QAbstractItemModel *>(), index.model());
        QCOMPARE(object->property("internalId").toULongLong(), index.internalId());

        if (i < 2) {
            index = model.index(2 + i, 4 - i, index);
            object->setPersistentModelIndex(index);
        } else if (i < 3) {
            model.removeRow(2);
            QVERIFY(!index.isValid()); // QPersistentModelIndex should update
            object->emitChanged(); // Help QML get the new values as QPMI doesn't emit anything
        } else if (i < 4) {
            index = model.index(2 + i, 4 - i);
            object->emitSignalWithPersistentModelIndex(index);
        }
    }

    const QVariant &pmiVariant = object->property("pmi");
    QCOMPARE(pmiVariant.type(), QVariant::UserType);
    QCOMPARE(pmiVariant.userType(), qMetaTypeId<QPersistentModelIndex>());
    QCOMPARE(pmiVariant.value<QPersistentModelIndex>(), QPersistentModelIndex(model.index(0, 0)));
}

void tst_qqmlitemmodels::itemSelectionRange()
{
    INIT_TEST_OBJECT("itemselectionrange.qml", object);
    TestModel model(10, 10);

    for (int i = 0; i < 2; i++) {
        const QVariant &isrVariant = object->property("itemSelectionRange");
        QCOMPARE(isrVariant.type(), QVariant::UserType);
        QCOMPARE(isrVariant.userType(), qMetaTypeId<QItemSelectionRange>());
        const QItemSelectionRange &isr = isrVariant.value<QItemSelectionRange>();
        if (i > 0) {
            QModelIndex parentIndex = model.index(0, 0);
            QCOMPARE(QModelIndex(isr.topLeft()), model.index(3, 0, parentIndex));
            QCOMPARE(QModelIndex(isr.bottomRight()), model.index(5, 6, parentIndex));
        } else {
            QCOMPARE(QModelIndex(isr.topLeft()), QModelIndex());
            QCOMPARE(QModelIndex(isr.bottomRight()), QModelIndex());
        }

        QCOMPARE(object->property("top").toInt(), isr.top());
        QCOMPARE(object->property("left").toInt(), isr.left());
        QCOMPARE(object->property("bottom").toInt(), isr.bottom());
        QCOMPARE(object->property("right").toInt(), isr.right());
        QCOMPARE(object->property("width").toInt(), isr.width());
        QCOMPARE(object->property("height").toInt(), isr.height());
        QCOMPARE(object->property("isValid").toBool(), isr.isValid());
        QCOMPARE(object->property("isEmpty").toBool(), isr.isEmpty());
        QCOMPARE(object->property("isrModel").value<QAbstractItemModel *>(), isr.model());

        // Set model for the 2nd iteration and test again
        object->setModel(&model);
    }

    // Check API function calls
    QVERIFY(object->property("contains1").toBool());
    QVERIFY(object->property("contains2").toBool());
    QVERIFY(!object->property("intersects").toBool());
    const QVariant &isrVariant = object->property("intersected");
    QCOMPARE(isrVariant.type(), QVariant::UserType);
    QCOMPARE(isrVariant.userType(), qMetaTypeId<QItemSelectionRange>());
}

void tst_qqmlitemmodels::modelIndexConversion()
{
    INIT_TEST_OBJECT("modelindexconversion.qml", object);
    TestModel model(10, 10);
    object->setModel(&model);

    QCOMPARE(object->modelIndex(), model.index(0, 0));
    QCOMPARE(object->persistentModelIndex(), QPersistentModelIndex(model.index(1, 1)));
}

void tst_qqmlitemmodels::itemSelection()
{
    INIT_TEST_OBJECT("itemselection.qml", object);
    TestModel model(10, 10);

    object->setModel(&model);
    QCOMPARE(object->property("count").toInt(), 8);
    QCOMPARE(object->property("contains").toBool(), true);

    QVariant milVariant = object->property("itemSelection");
    QCOMPARE(milVariant.type(), QVariant::UserType);
    QCOMPARE(milVariant.userType(), qMetaTypeId<QItemSelection>());

    const QItemSelection &mil = milVariant.value<QItemSelection>();
    QCOMPARE(mil.count(), 5);
}

void tst_qqmlitemmodels::modelIndexList()
{
    INIT_TEST_OBJECT("modelindexlist.qml", object);
    TestModel model(10, 10);

    object->setModel(&model);
    QCOMPARE(object->property("count").toInt(), 5);

    QVariant milVariant = object->property("modelIndexList");
    QCOMPARE(milVariant.type(), QVariant::UserType);
    QCOMPARE(milVariant.userType(), qMetaTypeId<QModelIndexList>());

    const QModelIndexList &mil = milVariant.value<QModelIndexList>();
    QCOMPARE(mil.count(), 2);
    QCOMPARE(mil.at(0), model.index(3, 3));
    QCOMPARE(mil.at(1), model.index(4, 4));
}

#undef INIT_TEST_OBJECT

QTEST_MAIN(tst_qqmlitemmodels)

#include "tst_qqmlitemmodels.moc"