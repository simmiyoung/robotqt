"""
robot.py
RobotQt - Robot Simulation

Created by Felipe Tonello on 2009-28-01.
Copyright 2009 Felipe Ferreri Tonello. All rights reserved.
http://robotqt.googlecode.com/

Revision: $Rev$
Author: $Author$
Date: $Date$
"""

from PyQt4 import QtCore
from Motor import Motor
from Sensor import Sensor

# TODO: debug message

class Robot(object):
    def __init__(self, name)
        self.name = QtCore.QString(name)
        self.stuff_list = []

    def set(self, stuff):
        if isinstance(stuff, Motor) or isinstance(stuff, Sensor)
            # If already exists or not
            if not _exists(stuff):
                self.stuff_list.append(stuff)
                return True
            else:
                raise Exception("stuff(%s) is not a Motor nor a Sensor" %
                stuff.__str__)
        else:
            # stuff is not a Motor nor a Sensor..
            raise Exception("stuff(%s) is not a Motor nor a Sensor" %
            stuff.__str__)

    def get(self, name):
        for stuff in self.stuff_list:
            if stuff.name == name:
                return stuff
        raise Exception("There is no Motor nor Sensor with name = %s" % name)

    def _exists(self, stuff):
        exists = False
        for s in self.stuff_list:
            if s.name == stuff.name:
                exists = True
                break
        return exists
