TEMPLATE = app
TARGET = RobotQt
QT += core \
    gui
HEADERS += src/robotcore/Robot.h \
    src/robotcore/RobotPosition.h \
    src/robotqt.h \
    src/robotcore/Motor/Motor.h \
    src/robotcore/Sensor/Sensor.h
SOURCES += src/robotcore/Robot.cpp \
    src/robotcore/RobotPosition.cpp \
    src/main.cpp \
    src/robotqt.cpp \
    src/robotcore/Motor/Motor.cpp \
    src/robotcore/Sensor/Sensor.cpp
FORMS += 
RESOURCES += 
