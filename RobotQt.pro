TEMPLATE = app
TARGET = RobotQt

CONFIG += qt # Support for Qt applications is enabled
CONFIG += debug_and_release # Support debug and release mode
CONFIG += warn_on # Show me warning please =)
CONFIG += thread # This is a multi-thread app
CONFIG += x11 # yes, we use X11 if available

# Qt modules to load
QT += core gui opengl

# Customize the names of the build targets depending on the target platform
CONFIG(debug, debug|release) {
    win32: TARGET = $$join(TARGET,,d) # Should return dRobotQt
    else: TARGET = $$join(TARGET,,,_debug) #Shoud return RobotQt_debug
}

# Where to install RobotQt
win32 {
    target.path = \RobotQt\
}
macx {
    target.path = /Applications/
}
unix {
    target.path = /usr/bin/
}

# Add RobotCore headers to plugin developers
headers.path = /usr/local/include/robotqt
headers.files = src/robotcore/robotcore.h \
    src/robotcore/robot.h \
    src/robotcore/robotposition.h \
    src/robotcore/motor/motor.h \
    src/robotcore/sensor/sensor.h

INSTALLS += target headers

HEADERS += src/robotcore/robot.h \
    src/robotcore/robotposition.h \
    src/robotqt.h \
    src/robotcore/motor/motor.h \
    src/robotcore/sensor/sensor.h \
    src/robotcore/robotcore.h \
    src/config.h
SOURCES += src/robotcore/robot.cpp \
    src/robotcore/robotposition.cpp \
    src/main.cpp \
    src/robotqt.cpp \
    src/robotcore/motor/motor.cpp \
    src/robotcore/sensor/sensor.cpp \
    src/robotcore/robotcore.cpp \
    src/config.cpp
INCLUDEPATH += src #For neat #include syntax

# If opengl module is available
CONFIG(opengl) {
    message(Building with OpenGL support.)
} else {
#    error(OpenGL support is not available.)
}

message(Congratulations! You are ready to build RobotQt.)
message(Type, to build: make)
message(Then type, to install\(as root user\): make install)
