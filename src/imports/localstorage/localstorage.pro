CXX_MODULE = qml
TARGET  = qmllocalstorageplugin
TARGETPATH = QtQuick/LocalStorage
IMPORT_VERSION = 2.0

QT = sql qml-private  core-private

SOURCES += plugin.cpp

load(qml_plugin)

OTHER_FILES += localstorage.json

QMAKE_CFLAGS_RELEASE+=-fno-strict-aliasing
QMAKE_CFLAGS_DEBUG+=-fno-strict-aliasing
QMAKE_CXXFLAGS_RELEASE+=-fno-strict-aliasing
QMAKE_CXXFLAGS_DEBUG+=-fno-strict-aliasing
