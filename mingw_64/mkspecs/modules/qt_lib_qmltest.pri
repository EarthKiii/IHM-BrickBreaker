QT.qmltest.VERSION = 6.5.0
QT.qmltest.name = QtQuickTest
QT.qmltest.module = Qt6QuickTest
QT.qmltest.libs = $$QT_MODULE_LIB_BASE
QT.qmltest.ldflags = 
QT.qmltest.includes = $$QT_MODULE_INCLUDE_BASE $$QT_MODULE_INCLUDE_BASE/QtQuickTest
QT.qmltest.frameworks = 
QT.qmltest.bins = $$QT_MODULE_BIN_BASE
QT.qmltest.depends =  core testlib
QT.qmltest.run_depends = gui qml_private quick quick_private qml
QT.qmltest.uses = 
QT.qmltest.module_config = v2
QT.qmltest.CONFIG = $
QT.qmltest.DEFINES = QT_QMLTEST_LIB
QT.qmltest.enabled_features = 
QT.qmltest.disabled_features = 
QT_CONFIG += 
QT_MODULES += qmltest

