# RobotQt
# Copyright (C) 2011 Felipe Ferreri Tonello <eu@felipetonello.com>

# RobotQt is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# RobotQt is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with RobotQt.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 2.8)

project(robotqt)

if(NOT DEFINED CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING
    "Choose the type of build, options are:
	 Debug
	 Release"
	)
endif()

set(ROBOQT_MAJOR 0)
set(ROBOQT_MINOR 0)
set(ROBOQT_RELEASE 1)
set(ROBOQT_NAME robotqt${ROBOQT_MAJOR}${ROBOQT_MINOR})
set(ROBOQT_VERSION ${ROBOQT_MAJOR}.${ROBOQT_MINOR}.${ROBOQT_RELEASE})

find_package(Qt4 COMPONENTS QtCore QtGui QtSvg QtXml REQUIRED)

include(${QT_USE_FILE})

set(ROBOTQT_ROOT_DIR ${PROJECT_SOURCE_DIR})
set(ROBOTQT_DOC_DIR ${ROBOTQT_ROOT_DIR}/doc)
set(ROBOTQT_IMAGES_DIR ${ROBOTQT_ROOT_DIR}/images)
set(ROBOTQT_SRC_DIR ${ROBOTQT_ROOT_DIR}/src)
set(ROBOTQT_UI_DIR ${ROBOTQT_ROOT_DIR}/ui)

set(ROBOTQT_ICON ${ROBOTQT_IMAGES_DIR}/robotqt.icns)

add_subdirectory(${ROBOTQT_SRC_DIR})
