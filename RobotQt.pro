TEMPLATE = app
TARGET = RobotQt

CONFIG += qt # Support for Qt applications is enabled
CONFIG += debug_and_release # Support debug and release mode
CONFIG += warn_on # Show me warning please =)
CONFIG += thread # This is a multi-thread app
CONFIG += x11 # use X11 if available

# Qt modules to load
QT += core \
    gui

# Customize the names of the build targets depending on the target platform
CONFIG(debug, debug|release) { 
    win32:TARGET = $$join(TARGET,,d) # Should return dRobotQt
    else:TARGET = $$join(TARGET,,,_debug) # Shoud return RobotQt_debug
}

# Where to install RobotQt and headers
win32 {
    target.path = \\RobotQt\\
    headers.path = \\RobotQt\\include
}
macx { 
    target.path = /Applications/
    headers.path = /usr/local/include/robotqt
}
unix { 
    target.path = /usr/bin/
    headers.path = /usr/local/include/robotqt
}

# Add RobotCore headers to plugin developers
headers.files = src/robotcore/robotinterface.h \
    src/robotcore/sensorinterface.h

INSTALLS += target \
    headers
HEADERS += src/robotqt.h \
    src/sourceeditor.h \
    src/robotcore/robotinterface.h \
    src/robotcore/sensorinterface.h \
    src/config.h \
    src/statusitem.h
SOURCES += src/main.cpp \
    src/robotqt.cpp \
    src/sourceeditor.cpp \
    src/config.cpp \
    src/statusitem.cpp
FORMS += src/ui/robotqt.ui \
    src/ui/sourceeditor.ui

# For neat #include syntax
INCLUDEPATH += src

message("Congratulations! You are ready to build RobotQt.")
message("To build, type 'make'")
message("Then to install\(as super user\), type 'make install'")
