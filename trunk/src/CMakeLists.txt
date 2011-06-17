# RobotQt
# Copyright (C) 2011 Felipe Ferreri Tonello <eu@felipetonello.com>

set(ROBOTQT_TARGET robotqt)

set(SOURCES_CPP
	main.cpp
	robotqt.cpp
	sourceeditor.cpp
	config.cpp
)

set(SOURCES_HEADERS_MOC
	robotqt.h
	sourceeditor.h
)

set(SOURCES_HEADERS
	config.h
	${SOURCES_HEADERS_MOC}
)

set(SOURCES_UI
	${ROBOTQT_UI_DIR}/robotqt.ui
	${ROBOTQT_UI_DIR}/sourceeditor.ui
)

set(SOURCES_QRC
	robotqt_imgs.qrc
)

# Icon for Mac OS X
if(APPLE)
	set(MACOSX_BUNDLE_ICON_FILE ${ROBOTQT_ICON})

	set_source_files_properties(${MACOSX_BUNDLE_ICON_FILE} PROPERTIES
		MACOSX_PACKAGE_LOCATION Resources
	)
endif(APPLE)

QT4_WRAP_CPP(GEN_SOURCES_MOC ${SOURCES_HEADERS_MOC})
QT4_WRAP_UI(GEN_SOURCES_UI ${SOURCES_UI})
QT4_ADD_RESOURCES(GEN_SOURCES_QRC ${SOURCES_QRC})

include_directories(
	${ROBOQT_SRC}
	${CMAKE_CURRENT_BINARY_DIR} # for ui_*.h headers
)

add_executable(${ROBOTQT_TARGET}
	${SOURCES_CPP}
	${SOURCES_HEADERS}
	${GEN_SOURCES_MOC}
	${GEN_SOURCES_UI}
	${GEN_SOURCES_QRC}
	${ROBOTQT_ICON}
)

target_link_libraries(${ROBOTQT_TARGET}
	${QT_LIBRARIES}
)
