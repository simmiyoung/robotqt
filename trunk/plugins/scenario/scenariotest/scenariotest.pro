TEMPLATE = lib
CONFIG += plugin
HEADERS = scenariotest.h
SOURCES = scenariotest.cpp \
    ../../../src/robotcore/pluginbase.cpp
# IMPORTANT: Remeber to change the extension name to .robot
TARGET = scenariotest.scenario
TARGET_EXT = scenario
