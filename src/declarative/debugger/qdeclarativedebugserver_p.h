/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QDECLARATIVEDEBUGSERVER_H
#define QDECLARATIVEDEBUGSERVER_H

#include <private/qdeclarativeglobal_p.h>
#include <private/qdeclarativedebugserverconnection_p.h>

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Declarative)

class QDeclarativeDebugService;

class QDeclarativeDebugServerPrivate;
class Q_DECLARATIVE_EXPORT QDeclarativeDebugServer : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(QDeclarativeDebugServer)
    Q_DISABLE_COPY(QDeclarativeDebugServer)
public:
    ~QDeclarativeDebugServer();

    static QDeclarativeDebugServer *instance();

    void setConnection(QDeclarativeDebugServerConnection *connection);

    bool hasDebuggingClient() const;

    QList<QDeclarativeDebugService*> services() const;
    QStringList serviceNames() const;


    bool addService(QDeclarativeDebugService *service);
    bool removeService(QDeclarativeDebugService *service);

    void receiveMessage(const QByteArray &message);

    bool waitForMessage(QDeclarativeDebugService *service);
    void sendMessage(QDeclarativeDebugService *service, const QByteArray &message);

private:
    friend class QDeclarativeDebugService;
    friend class QDeclarativeDebugServicePrivate;
    friend class QDeclarativeDebugServerThread;
    QDeclarativeDebugServer();
    Q_PRIVATE_SLOT(d_func(), void _q_sendMessage(QByteArray))
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QDECLARATIVEDEBUGSERVICE_H
