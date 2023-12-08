cmake_minimum_required(VERSION 3.5)

project(powerpoint VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(powerpoint
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        mywidget.hpp mywidget.cpp
        mainwindow.hpp mainwindow.cpp
        configuration.hpp configuration.cpp
        Shapes/Circle.cpp Shapes/Circle.hpp
        Shapes/Rectangle.hpp Shapes/Rectangle.cpp
        Shapes/Triangle.hpp Shapes/Triangle.cpp
        Shapes/ShapeBase.hpp Shapes/ShapeBase.cpp
        Parser.hpp Parser.cpp
        Registries/ShapeRegistry.hpp Registries/ShapeRegistry.cpp
        Commands/AddCommand.hpp Commands/AddCommand.cpp
        Commands/Command.hpp
        Commands/DisplayCommand.hpp Commands/DisplayCommand.cpp



    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET powerpoint APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(powerpoint SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(powerpoint
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(powerpoint PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.powerpoint)
endif()
set_target_properties(powerpoint PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS powerpoint
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(powerpoint)
endif()
