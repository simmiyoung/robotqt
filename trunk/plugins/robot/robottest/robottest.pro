TEMPLATE = lib
CONFIG += plugin
HEADERS = robottest.h
SOURCES = robottest.cpp \
    ../../../src/robotcore/pluginbase.cpp
# IMPORTANT: Remeber to change the extension name to .robot
TARGET = robottest.robot
TARGET_EXT = robot
