TARGET = notifyosdconf
TEMPLATE = app
SOURCES += main.cpp mainwindow.cpp aboutw.cpp util.cpp
HEADERS += mainwindow.h aboutw.h util.h
FORMS += mainwindow.ui  aboutw.ui
include(qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.pri)
OTHER_FILES +=
RESOURCES += res.qrc

QMAKE_CXX = clang++
QMAKE_CC = clang
QMAKE_CLEAN += notifyosdconf

share_files.path = /usr/share/notifyosdconf/
share_files.files += not.png
share_files.files += default.def
INSTALLS += share_files

desktop_entry.path = /usr/share/applications/
desktop_entry.files = notifyconf.desktop
INSTALLS += desktop_entry

bin_app.path = /usr/bin/
bin_app.files = notifyosdconf
INSTALLS += bin_app
