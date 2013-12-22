TARGET = notifyosdconf
TEMPLATE = app
SOURCES += main.cpp mainwindow.cpp aboutw.cpp
HEADERS += mainwindow.h aboutw.h
FORMS += mainwindow.ui  aboutw.ui
include(qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.pri)
OTHER_FILES +=
RESOURCES += res.qrc

QMAKE_CXX = clang++
QMAKE_CC = clang
QMAKE_CLEAN += notifyosdconf
