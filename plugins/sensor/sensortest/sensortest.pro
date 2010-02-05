TEMPLATE = lib
CONFIG += plugin
HEADERS = sensortest.h
SOURCES = sensortest.cpp \
    ../../../src/robotcore/pluginbase.cpp
# IMPORTANT: Remeber to change the extension name to .sensor
TARGET = sensortest.sensor
TARGET_EXT = sensor
