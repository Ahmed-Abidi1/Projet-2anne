cmake_minimum_required(VERSION 3.16)

project(proji VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Multimedia MultimediaWidgets Sql PrintSupport Network Charts Quick QuickWidgets Location Positioning SerialPort)  # ADD SerialPort here
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Multimedia MultimediaWidgets Sql PrintSupport Network Charts Quick QuickWidgets Location Positioning SerialPort)  # AND here

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    appar_fonction.cpp
    appar_fonction.h
    appar_fonction.ui
    appar_modifier.cpp
    appar_modifier.h
    appar_modifier.ui
    connection.cpp
    connection.h
    appartement.cpp
    appartement.h
    arduinomonitor.h
    arduinomonitor.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(proji
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        vehicules.h vehicules.cpp
        materiel.h materiel.cpp
        espace.h espace.cpp
        employe.h employe.cpp
        vehicule_inter.h vehicule_inter.cpp vehicule_inter.ui
        vehicule_fonc.h vehicule_fonc.cpp vehicule_fonc.ui
        espace_inter.h espace_inter.cpp espace_inter.ui
        espace_fonc.h espace_fonc.cpp espace_fonc.ui
        espace_modifier.h espace_modifier.cpp espace_modifier.ui
        mate_inter.h mate_inter.cpp mate_inter.ui
        mate_fonc.h mate_fonc.cpp mate_fonc.ui
        employe_inter.h employe_inter.cpp employe_inter.ui
        employe_fonc.h employe_fonc.cpp employe_fonc.ui
    )
else()
    add_executable(proji ${PROJECT_SOURCES})
endif()

target_link_libraries(proji PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::MultimediaWidgets
    Qt${QT_VERSION_MAJOR}::Sql
    Qt${QT_VERSION_MAJOR}::PrintSupport
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Charts
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::QuickWidgets
    Qt${QT_VERSION_MAJOR}::Location
    Qt${QT_VERSION_MAJOR}::Positioning
    Qt${QT_VERSION_MAJOR}::SerialPort  # ADD this line
)

set_target_properties(proji PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(proji)
endif()
