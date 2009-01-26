#############################################################################
# Makefile for building: RobotQt
# Generated by qmake (2.01a) (Qt 4.4.3) on: Wed Jan 14 03:15:53 2009
# Project:  RobotQt.pro
# Template: app
# Command: /usr/local/Trolltech/Qt-4.4.3/bin/qmake -unix -o Makefile RobotQt.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/local/Trolltech/Qt-4.4.3/mkspecs/linux-g++-64 -I. -I/usr/local/Trolltech/Qt-4.4.3/include/QtCore -I/usr/local/Trolltech/Qt-4.4.3/include/QtCore -I/usr/local/Trolltech/Qt-4.4.3/include/QtGui -I/usr/local/Trolltech/Qt-4.4.3/include/QtGui -I/usr/local/Trolltech/Qt-4.4.3/include -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-rpath,/usr/local/Trolltech/Qt-4.4.3/lib
LIBS          = $(SUBLIBS)  -L/usr/local/Trolltech/Qt-4.4.3/lib -lQtGui -L/usr/local/Trolltech/Qt-4.4.3/lib -L/usr/X11R6/lib64 -lXext -lX11 -lQtCore -lm -lrt -ldl -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/local/Trolltech/Qt-4.4.3/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = src/robotcore/robot.cpp \
		src/robotcore/robotposition.cpp \
		src/main.cpp \
		src/robotqt.cpp \
		src/robotcore/motor/motor.cpp \
		src/robotcore/sensor/sensor.cpp \
		src/robotcore/core.cpp \
		src/config.cpp moc_robotqt.cpp
OBJECTS       = robot.o \
		robotposition.o \
		main.o \
		robotqt.o \
		motor.o \
		sensor.o \
		core.o \
		config.o \
		moc_robotqt.o
DIST          = /usr/local/Trolltech/Qt-4.4.3/mkspecs/common/g++.conf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/release.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/lex.prf \
		RobotQt.pro
QMAKE_TARGET  = RobotQt
DESTDIR       = 
TARGET        = RobotQt

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

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: RobotQt.pro  /usr/local/Trolltech/Qt-4.4.3/mkspecs/linux-g++-64/qmake.conf /usr/local/Trolltech/Qt-4.4.3/mkspecs/common/g++.conf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/release.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.4.3/lib/libQtGui.prl \
		/usr/local/Trolltech/Qt-4.4.3/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile RobotQt.pro
/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/g++.conf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/unix.conf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/linux.conf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/qconfig.pri:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_functions.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_config.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/exclusive_builds.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_pre.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/release.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_post.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/warn_on.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/unix/thread.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/moc.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/resources.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/uic.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/yacc.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/lex.prf:
/usr/local/Trolltech/Qt-4.4.3/lib/libQtGui.prl:
/usr/local/Trolltech/Qt-4.4.3/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile RobotQt.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/RobotQt1.0.0 || $(MKDIR) .tmp/RobotQt1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/RobotQt1.0.0/ && $(COPY_FILE) --parents src/robotcore/robot.h src/robotcore/robotposition.h src/robotqt.h src/robotcore/motor/motor.h src/robotcore/sensor/sensor.h src/robotcore/core.h src/config.h .tmp/RobotQt1.0.0/ && $(COPY_FILE) --parents src/robotcore/robot.cpp src/robotcore/robotposition.cpp src/main.cpp src/robotqt.cpp src/robotcore/motor/motor.cpp src/robotcore/sensor/sensor.cpp src/robotcore/core.cpp src/config.cpp .tmp/RobotQt1.0.0/ && (cd `dirname .tmp/RobotQt1.0.0` && $(TAR) RobotQt1.0.0.tar RobotQt1.0.0 && $(COMPRESS) RobotQt1.0.0.tar) && $(MOVE) `dirname .tmp/RobotQt1.0.0`/RobotQt1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/RobotQt1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_robotqt.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_robotqt.cpp
moc_robotqt.cpp: src/robotqt.h
	/usr/local/Trolltech/Qt-4.4.3/bin/moc $(DEFINES) $(INCPATH) src/robotqt.h -o moc_robotqt.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

robot.o: src/robotcore/robot.cpp src/robotcore/robot.h \
		src/robotcore/core.h \
		src/config.h \
		src/robotcore/motor/motor.h \
		src/robotcore/sensor/sensor.h \
		src/robotcore/robotposition.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o robot.o src/robotcore/robot.cpp

robotposition.o: src/robotcore/robotposition.cpp src/robotcore/robotposition.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o robotposition.o src/robotcore/robotposition.cpp

main.o: src/main.cpp src/robotqt.h \
		src/config.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o src/main.cpp

robotqt.o: src/robotqt.cpp src/robotqt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o robotqt.o src/robotqt.cpp

motor.o: src/robotcore/motor/motor.cpp src/robotcore/motor/motor.h \
		src/robotcore/core.h \
		src/config.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o motor.o src/robotcore/motor/motor.cpp

sensor.o: src/robotcore/sensor/sensor.cpp src/robotcore/sensor/sensor.h \
		src/robotcore/core.h \
		src/config.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sensor.o src/robotcore/sensor/sensor.cpp

core.o: src/robotcore/core.cpp src/robotcore/core.h \
		src/config.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o core.o src/robotcore/core.cpp

config.o: src/config.cpp src/config.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o config.o src/config.cpp

moc_robotqt.o: moc_robotqt.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_robotqt.o moc_robotqt.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

