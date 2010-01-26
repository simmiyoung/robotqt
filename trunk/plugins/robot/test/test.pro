TEMPLATE = lib
CONFIG += plugin
HEADERS = test.h \
    ../../../src/robotcore/robotinterface.h
SOURCES = test.cpp \
    ../../../src/robotcore/pluginbase.cpp
TARGET = test.robot
TARGET_EXT = robot
