TEMPLATE = app
TARGET = RobotQt
QT += core \
    gui
HEADERS += src/robotcore/robot.h \
    src/robotcore/robotposition.h \
    src/robotqt.h \
    src/robotcore/motor/motor.h \
    src/robotcore/sensor/sensor.h \
    src/robotcore/core.h \
    src/config.h
SOURCES += src/robotcore/robot.cpp \
    src/robotcore/robotposition.cpp \
    src/main.cpp \
    src/robotqt.cpp \
    src/robotcore/motor/motor.cpp \
    src/robotcore/sensor/sensor.cpp \
    src/robotcore/core.cpp \
    src/config.cpp
FORMS += 
RESOURCES += 
