Name:       qt5-qtdeclarative
Summary:    Qt Declarative library
Version:    5.6.3+git20
Release:    1%{?dist}
License:    (LGPLv2 or LGPLv3) with exception or GPLv3 or Qt Commercial
URL:        https://www.qt.io/
Source0:    %{name}-%{version}.tar.bz2
BuildRequires:  qt5-qtcore-devel >= 5.6.3
BuildRequires:  qt5-qtgui-devel >= 5.6.3
BuildRequires:  qt5-qtnetwork-devel
BuildRequires:  qt5-qtsql-devel
BuildRequires:  qt5-qttest-devel
BuildRequires:  qt5-qtxmlpatterns-devel
BuildRequires:  qt5-qmake
BuildRequires:  fdupes
BuildRequires:  python3-base
BuildRequires:  gdb
BuildRequires:  qml-rpm-macros
Obsoletes: qt5-qtjsbackend <= 5.1.0+git4
Provides: qt5-qtjsbackend > 5.1.0+git4

%description
Qt is a cross-platform application and UI framework. Using Qt, you can
write web-enabled applications once and deploy them across desktop,
mobile and embedded systems without rewriting the source code.
.
This package contains the Declarative library


%package devel
Summary:    Qt Declarative - development files
Requires:   %{name} = %{version}-%{release}
Requires:   qt5-qtsql-devel
Requires:   qt5-qtnetwork-devel
Requires:   qml-rpm-macros

%description devel
Qt is a cross-platform application and UI framework. Using Qt, you can
write web-enabled applications once and deploy them across desktop,
mobile and embedded systems without rewriting the source code.
.
This package contains the Declarative library development files

%package doc
Summary:    Qt Declarative - documentation
Requires:   %{name} = %{version}-%{release}

%description doc
This package contains the Qt Declarative documentation

%package qtquicktest
Summary:    Qt Declarative QtQuickTest library
Requires:   %{name} = %{version}-%{release}
Requires(post):     /sbin/ldconfig
Requires(postun):   /sbin/ldconfig

%description qtquicktest
This package contains the QtQuickTest library for QtDeclarative module

%package qtquicktest-devel
Summary:    Qt Declarative QtQuickTest - development files
Requires:   %{name} = %{version}-%{release}
Requires:   %{name}-devel = %{version}-%{release}
Requires:   qt5-qtdeclarative-qtquicktest = %{version}-%{release}

%description qtquicktest-devel
This package contains the development headers for QtQuickTest library

%package qtquick
Summary:    Qt Declarative - QtQuick library
Requires:   %{name} = %{version}-%{release}
Obsoletes: qt5-qtdeclarative-plugin-accessible

%description qtquick
This package contains the QtQuick QML support library

%package qtquick-devel
Summary:    Qt Declarative - QtQuick development files
Requires:   %{name} = %{version}-%{release}
Requires:   qt5-qtdeclarative-qtquick = %{version}-%{release}

%description qtquick-devel
This package contains the development headers for legacy QtQuick 1
QML support library

%package qtquick-doc
Summary:    Qt Declarative - QtQuick documentation
Requires:   %{name} = %{version}-%{release}
Requires:   qt5-qtdeclarative-qtquick = %{version}-%{release}

%description qtquick-doc
This package contains the Qt Declarative QtQuick documentation

%package qtquickparticles
Summary:    Qt Declarative - QtQuick Particles library
Requires:   %{name} = %{version}-%{release}

%description qtquickparticles
This package contains the QtQuick Particles support library

%package qtquickparticles-devel
Summary:    Qt Declarative - QtQuick Particles development files
Requires:   %{name} = %{version}-%{release}
Requires:   qt5-qtdeclarative-qtquickparticles = %{version}-%{release}

%description qtquickparticles-devel
This package contains the development headers for QtQuickParticles
QML support library

%package qtdeclarativetools-devel
Summary:    Qt Declarative QtQmlDevTools - development files
Requires:   %{name} = %{version}-%{release}
Requires:   %{name}-devel = %{version}-%{release}
Requires:   qt5-qtdeclarative-devel = %{version}-%{release}

%description qtdeclarativetools-devel
This package contains the development headers for QtQmlDevTools



#### Small plugin and import packages

%package import-folderlistmodel
Summary:    Qt Declarative folderlistmodel plugin
Requires:   %{name} = %{version}-%{release}

%description import-folderlistmodel
This package provides the QtQml folderlistmodel plugin

%package import-settings
Summary:    Qt Declarative settings plugin
Requires:   %{name} = %{version}-%{release}

%description import-settings
This package provides the %{summary}

%package import-localstorageplugin
Summary:    Qt LocalStorage plugin
Requires:   %{name} = %{version}-%{release}

%description import-localstorageplugin
This package provided the Qt LocalStorage plugin

%package plugin-qmlinspector
Summary:    Qt Declarative QML inspector plugin
Requires:   %{name} = %{version}-%{release}

%description plugin-qmlinspector
This package provides the QML inspector plugin

%package import-qtquick2plugin
Summary:    Qt Declarative QtQuick 2 support plugin
Requires:   %{name} = %{version}-%{release}

%description import-qtquick2plugin
This package provides the QtQuick 2 support plugin

%package import-qttest
Summary:    Qt Declarative QtTest plugin
Requires:   %{name} = %{version}-%{release}

%description import-qttest
This package provides the QtQml QtTest plugin

%package import-particles2
Summary:    Qt Declarative Particles plugin
Requires:   %{name} = %{version}-%{release}

%description import-particles2
This package provides the QtQml Particles.2 plugin

%package import-window2
Summary:    Qt Declarative Window plugin
Requires:   %{name} = %{version}-%{release}

%description import-window2
This package provides the QtQml Window.2 plugin

%package import-models2
Summary:    Qt Declarative models plugin
Requires:   %{name} = %{version}-%{release}

%description import-models2
This package provides the QtDeclarative models plugin for QtQuick 2.0

%package import-xmllistmodel
Summary:    Qt Declarative XmlListModel plugin
Requires:   %{name} = %{version}-%{release}

%description import-xmllistmodel
This package provides the QtDeclarative XmlListModel plugin for QtQuick 2.0

%package qmlscene
Summary:    QML scene viewer
Requires:   %{name} = %{version}-%{release}
Requires:   qtchooser

%description qmlscene
This package contains the QML viewer for QtQuick 2.0 files.

%package tool-qml
Summary:    QML runtime binary
Requires:   %{name} = %{version}-%{release}

%description tool-qml
This package contains the %{summary} tool

%package devel-tools
Summary:    QML development tools
Requires:   %{name} = %{version}-%{release}
Provides:   %{name}-tool-qmlimportscanner
Conflicts:  %{name}-tool-qmlimportscanner < 5.6.3+git10
Requires:   qtchooser

%description devel-tools
This package contains QML debugging and development tools

%package plugin-qmlstatemachine
Summary:    Qt Declarative QML State Machine plugin
Requires:   %{name} = %{version}-%{release}

%description plugin-qmlstatemachine
This package provides the QML State Machine plugin



%prep
%autosetup -n %{name}-%{version}

%build
touch .git

%ifarch %arm
# to enable JIT, we need to enable thumb, as it is the only supported
# configuration for JIT on ARM. unfortunately, we are not currently in the right
# frame of mind to be able to deal with a full thumb transition, so we need to
# hack it in.
#
# OBS forces -mno-thumb, so first step, we need to remove that, and then add our
# own thumb argument. we can't do this in the .pro, as it won't propegate. we
# can't do it in .qmake.conf, because that's loaded too early. -after is *just*
# the right place: it's after everything has happened except for
# default_post.prf, which sets up the real QMAKE_C{XX}FLAGS, so brutally abuse
# it to acomplish our evil goals.
%qmake5 \
    QT.widgets.name= DEFINES+=QT_NO_WIDGETS \
    -after \
    QMAKE_CFLAGS_RELEASE-=-mno-thumb     QMAKE_CFLAGS_DEBUG-=-mno-thumb \
    QMAKE_CXXFLAGS_RELEASE-=-mno-thumb   QMAKE_CXXFLAGS_DEBUG-=-mno-thumb \
    QMAKE_CFLAGS_RELEASE+=-mthumb        QMAKE_CFLAGS_DEBUG+=-mthumb \
    QMAKE_CXXFLAGS_RELEASE+=-mthumb      QMAKE_CXXFLAGS_DEBUG+=-mthumb
%else
%qmake5 QT.widgets.name= DEFINES+=QT_NO_WIDGETS
%endif

%make_build

%install
%qmake5_install
# Fix wrong path in pkgconfig files
find %{buildroot}%{_qt5_libdir}/pkgconfig -type f -name '*.pc' \
-exec perl -pi -e "s, -L%{_builddir}/?\S+,,g" {} \;
# Fix wrong path in prl files
find %{buildroot}%{_qt5_libdir} -type f -name '*.prl' \
-exec sed -i -e "/^QMAKE_PRL_BUILD_DIR/d;s/\(QMAKE_PRL_LIBS =\).*/\1/" {} \;
# Remove unneeded .la files
rm -f %{buildroot}/%{_qt5_libdir}/*.la

# We don't need qt5/Qt/
rm -rf %{buildroot}/%{_qt5_includedir}/Qt

# Manually copy qmldevtools static library
cp lib/libQt5QmlDevTools.a %{buildroot}/%{_qt5_libdir}
%fdupes %{buildroot}/%{_libdir}
%fdupes %{buildroot}/%{_includedir}


# Copy docs
mkdir -p %{buildroot}/%{_qt5_docdir}/qtqml
mkdir -p %{buildroot}/%{_qt5_docdir}/qtquick


#### Pre/Post section

%post -p /sbin/ldconfig
%postun -p /sbin/ldconfig

%post qtquicktest -p /sbin/ldconfig
%postun qtquicktest -p /sbin/ldconfig

%post qtquick -p /sbin/ldconfig
%postun qtquick -p /sbin/ldconfig


%post qtquickparticles -p /sbin/ldconfig
%postun qtquickparticles -p /sbin/ldconfig





#### File section


%files
%defattr(-,root,root,-)
%license LICENSE.LGPLv* LGPL_EXCEPTION.txt LICENSE.GPLv3
%{_qt5_libdir}/libQt5Qml.so.5
%{_qt5_libdir}/libQt5Qml.so.5.*

%files devel
%defattr(-,root,root,-)
%{_qt5_libdir}/libQt5Qml.so
%{_qt5_libdir}/libQt5Qml.prl
%{_qt5_libdir}/pkgconfig/Qt5Qml.pc
%{_qt5_archdatadir}/qml/builtins.qmltypes
%{_qt5_archdatadir}/qml/QtQml/plugins.qmltypes
%{_qt5_archdatadir}/qml/QtQml/qmldir
%{_qt5_includedir}/QtQml/
%{_qt5_archdatadir}/mkspecs/modules/qt_lib_qml.pri
%{_qt5_archdatadir}/mkspecs/modules/qt_lib_qml_private.pri
%{_qt5_libdir}/cmake/Qt5Qml/Qt5QmlConfig.cmake
%{_qt5_libdir}/cmake/Qt5Qml/Qt5QmlConfigExtras.cmake
%{_qt5_libdir}/cmake/Qt5Qml/Qt5QmlConfigVersion.cmake


%files doc
%{_qt5_docdir}/qtqml*

%files qtquick
%defattr(-,root,root,-)
%{_qt5_libdir}/libQt5Quick.so.5
%{_qt5_libdir}/libQt5Quick.so.5.*

%files qtquick-devel
%defattr(-,root,root,-)
%{_qt5_libdir}/libQt5Quick.so
%{_qt5_libdir}/libQt5Quick.prl
%{_qt5_libdir}/pkgconfig/Qt5Quick.pc
%{_qt5_includedir}/QtQuick/
%{_qt5_archdatadir}/mkspecs/modules/qt_lib_quick.pri
%{_qt5_archdatadir}/mkspecs/modules/qt_lib_quick_private.pri
%{_qt5_libdir}/cmake/Qt5Quick/Qt5QuickConfig.cmake
%{_qt5_libdir}/cmake/Qt5Quick/Qt5QuickConfigVersion.cmake

%files qtquick-doc
%{_qt5_docdir}/qtquick*





%files qmlscene
%defattr(-,root,root,-)
%{_qt5_bindir}/qmlscene

%files tool-qml
%defattr(-,root,root,-)
%{_qt5_bindir}/qml

%files devel-tools
%defattr(-,root,root,-)
%{_qt5_bindir}/qmlimportscanner
%{_qt5_bindir}/qmlplugindump
%{_qt5_bindir}/qmlprofiler
%{_qt5_bindir}/qmltestrunner
%{_qt5_bindir}/qmlmin
%{_qt5_bindir}/qmllint


%files import-folderlistmodel
%defattr(-,root,root,-)
%{_qt5_archdatadir}/qml/Qt/labs/folderlistmodel/*

%files import-settings
%defattr(-,root,root,-)
%{_qt5_archdatadir}/qml/Qt/labs/settings/*

%files import-localstorageplugin
%defattr(-,root,root,-)
%{_qt5_archdatadir}/qml/QtQuick/LocalStorage/

%files plugin-qmlinspector
%defattr(-,root,root,-)
%{_qt5_archdatadir}/plugins/qmltooling/*
%{_qt5_libdir}/cmake/Qt5Qml/Qt5Qml_QLocalClientConnectionFactory.cmake
%{_qt5_libdir}/cmake/Qt5Qml/Qt5Qml_QQmlInspectorServiceFactory.cmake
%{_qt5_libdir}/cmake/Qt5Qml/Qt5Qml_QTcpServerConnectionFactory.cmake
%{_qt5_libdir}/cmake/Qt5Qml/Qt5Qml_QQmlDebugServerFactory.cmake
%{_qt5_libdir}/cmake/Qt5Qml/Qt5Qml_QQmlNativeDebugConnectorFactory.cmake
%{_qt5_libdir}/cmake/Qt5Qml/Qt5Qml_QQmlDebuggerServiceFactory.cmake
%{_qt5_libdir}/cmake/Qt5Qml/Qt5Qml_QQmlProfilerServiceFactory.cmake

%files import-qttest
%defattr(-,root,root,-)
%{_qt5_archdatadir}/qml/QtTest/

%files import-qtquick2plugin
%defattr(-,root,root,-)
%{_qt5_archdatadir}/qml/QtQuick.2/

%files import-particles2
%defattr(-,root,root,-)
%{_qt5_archdatadir}/qml/QtQuick/Particles.2/

%files import-window2
%defattr(-,root,root,-)
%{_qt5_archdatadir}/qml/QtQuick/Window.2/

%files import-models2
%defattr(-,root,root,-)
%{_qt5_archdatadir}/qml/QtQml/Models.2/

%files import-xmllistmodel
%defattr(-,root,root,-)
%{_qt5_archdatadir}/qml/QtQuick/XmlListModel/



%files qtquicktest
%defattr(-,root,root,-)
%{_qt5_libdir}/libQt5QuickTest.so.5
%{_qt5_libdir}/libQt5QuickTest.so.5.*

%files qtquicktest-devel
%defattr(-,root,root,-)
%{_qt5_includedir}/QtQuickTest/
%{_qt5_libdir}/libQt5QuickTest.so
%{_qt5_libdir}/libQt5QuickTest.prl
%{_qt5_libdir}/pkgconfig/Qt5QuickTest.pc
%{_qt5_archdatadir}/mkspecs/modules/qt_lib_qmltest.pri
%{_qt5_archdatadir}/mkspecs/modules/qt_lib_qmltest_private.pri
%{_qt5_libdir}/cmake/Qt5QuickTest/Qt5QuickTestConfig.cmake
%{_qt5_libdir}/cmake/Qt5QuickTest/Qt5QuickTestConfigVersion.cmake

%files qtquickparticles
%defattr(-,root,root,-)
%{_qt5_libdir}/libQt5QuickParticles.so.5
%{_qt5_libdir}/libQt5QuickParticles.so.5.*

%files qtquickparticles-devel
%defattr(-,root,root,-)
%{_qt5_includedir}/QtQuickParticles/
%{_qt5_libdir}/libQt5QuickParticles.so
%{_qt5_libdir}/libQt5QuickParticles.prl
%{_qt5_archdatadir}/mkspecs/modules/qt_lib_quickparticles_private.pri

%files qtdeclarativetools-devel
%defattr(-,root,root,-)
%{_qt5_libdir}/libQt5QmlDevTools.a
%{_qt5_libdir}/libQt5QmlDevTools.prl
%{_qt5_includedir}/QtQmlDevTools/
%{_qt5_archdatadir}/mkspecs/modules/qt_lib_qmldevtools_private.pri

%files plugin-qmlstatemachine
%defattr(-,root,root,-)
%{_qt5_archdatadir}/qml/QtQml/StateMachine//

