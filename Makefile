#############################################################################
# Makefile for building: NotifyOSDConfiguration
# Generated by qmake (2.01a) (Qt 4.6.2) on: Sun May 16 21:53:34 2010
# Project:  NotifyOSDConfiguration.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix -o Makefile NotifyOSDConfiguration.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -Iqtcolorpicker-2.6_1-opensource/src -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		aboutw.cpp \
		qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.cpp moc_mainwindow.cpp \
		moc_aboutw.cpp \
		moc_qtcolorpicker.cpp \
		qrc_res.cpp
OBJECTS       = main.o \
		mainwindow.o \
		aboutw.o \
		qtcolorpicker.o \
		moc_mainwindow.o \
		moc_aboutw.o \
		moc_qtcolorpicker.o \
		qrc_res.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		qtcolorpicker-2.6_1-opensource/common.pri \
		qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.pri \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		NotifyOSDConfiguration.pro
QMAKE_TARGET  = NotifyOSDConfiguration
DESTDIR       = 
TARGET        = NotifyOSDConfiguration

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_aboutw.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: NotifyOSDConfiguration.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		qtcolorpicker-2.6_1-opensource/common.pri \
		qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.pri \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix -o Makefile NotifyOSDConfiguration.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
qtcolorpicker-2.6_1-opensource/common.pri:
qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.pri:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix -o Makefile NotifyOSDConfiguration.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/NotifyOSDConfiguration1.0.0 || $(MKDIR) .tmp/NotifyOSDConfiguration1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/NotifyOSDConfiguration1.0.0/ && $(COPY_FILE) --parents mainwindow.h aboutw.h qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.h .tmp/NotifyOSDConfiguration1.0.0/ && $(COPY_FILE) --parents res.qrc .tmp/NotifyOSDConfiguration1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp aboutw.cpp qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.cpp .tmp/NotifyOSDConfiguration1.0.0/ && $(COPY_FILE) --parents mainwindow.ui aboutw.ui .tmp/NotifyOSDConfiguration1.0.0/ && (cd `dirname .tmp/NotifyOSDConfiguration1.0.0` && $(TAR) NotifyOSDConfiguration1.0.0.tar NotifyOSDConfiguration1.0.0 && $(COMPRESS) NotifyOSDConfiguration1.0.0.tar) && $(MOVE) `dirname .tmp/NotifyOSDConfiguration1.0.0`/NotifyOSDConfiguration1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/NotifyOSDConfiguration1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_aboutw.cpp moc_qtcolorpicker.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_aboutw.cpp moc_qtcolorpicker.cpp
moc_mainwindow.cpp: mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_aboutw.cpp: aboutw.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) aboutw.h -o moc_aboutw.cpp

moc_qtcolorpicker.cpp: qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.h -o moc_qtcolorpicker.cpp

compiler_rcc_make_all: qrc_res.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_res.cpp
qrc_res.cpp: res.qrc \
		not.png
	/usr/bin/rcc -name res res.qrc -o qrc_res.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all: qtcolorpicker.moc
compiler_moc_source_clean:
	-$(DEL_FILE) qtcolorpicker.moc
qtcolorpicker.moc: qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.h \
		qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.cpp
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.cpp -o qtcolorpicker.moc

compiler_uic_make_all: ui_mainwindow.h ui_aboutw.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_aboutw.h
ui_mainwindow.h: mainwindow.ui \
		qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.h
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

ui_aboutw.h: aboutw.ui
	/usr/bin/uic-qt4 aboutw.ui -o ui_aboutw.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_moc_source_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		ui_mainwindow.h \
		qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.h \
		ui_dialog.h \
		aboutw.h \
		ui_aboutw.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

aboutw.o: aboutw.cpp aboutw.h \
		ui_aboutw.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o aboutw.o aboutw.cpp

qtcolorpicker.o: qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.cpp qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.h \
		qtcolorpicker.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qtcolorpicker.o qtcolorpicker-2.6_1-opensource/src/qtcolorpicker.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_aboutw.o: moc_aboutw.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_aboutw.o moc_aboutw.cpp

moc_qtcolorpicker.o: moc_qtcolorpicker.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qtcolorpicker.o moc_qtcolorpicker.cpp

qrc_res.o: qrc_res.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_res.o qrc_res.cpp

####### Install

install:
	$(MKDIR) $(HOME)/.notifyosdconf/
	chmod -R 777 $(HOME)/.notifyosdconf/
	$(INSTALL_FILE) not.png $(HOME)/.notifyosdconf/not.png
	$(INSTALL_FILE) default.def $(HOME)/.notifyosdconf/default.def
	$(INSTALL_PROGRAM) NotifyOSDConfiguration /usr/bin/notifyconf
	echo "[Desktop Entry]" > /usr/share/applications/notifyconf.desktop
	echo "Encoding=UTF-8" >> /usr/share/applications/notifyconf.desktop
	echo "Version=1.0" >> /usr/share/applications/notifyconf.desktop
	echo "Type=Application" >> /usr/share/applications/notifyconf.desktop
	echo "Name=NotifyOSD Configuration" >> /usr/share/applications/notifyconf.desktop
	echo "Comment=Tool to configure Ubuntu's notify-osd notification system" >> /usr/share/applications/notifyconf.desktop
	echo "Categories=GNOME;Applications;Utility;Qt" >> /usr/share/applications/notifyconf.desktop
	echo "Exec=notifyconf" >> /usr/share/applications/notifyconf.desktop
	echo "Icon=$(HOME)/.notifyosdconf/not.png" >> /usr/share/applications/notifyconf.desktop

uninstall:
	rm -r $(HOME)/.notifyosdconf/
	$(DEL_FILE) /usr/bin/notifyconf
	$(DEL_FILE) /usr/share/applications/notifyconf.desktop

FORCE:

