TEMPLATE = lib
CONFIG += plugin
HEADERS = test.h
SOURCES = test.cpp \
    ../../../src/robotcore/pluginbase.cpp
# IMPORTANT: Remeber to change the extension name to .robot
TARGET = test.robot
TARGET_EXT = robot
