TEMPLATE = app
TARGET = RobotQt
QT += core \
    gui
HEADERS += src/robotcore/Robot.h \
    src/robotcore/RobotPosition.h \
    src/robotqt.h
SOURCES += src/robotcore/Robot.cpp \
    src/robotcore/RobotPosition.cpp \
    src/main.cpp \
    src/robotqt.cpp
FORMS += src/ui/robotqt.ui
RESOURCES += 
