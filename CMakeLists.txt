cmake_minimum_required(VERSION 3.19)

project(gitlfs-gui-by-sea5kg LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)

set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_SKIP_BUILD_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "$ORIGIN")

set(CMAKE_AUTOMOC TRUE)
set(CMAKE_AUTOUIC TRUE)
set(CMAKE_AUTORCC TRUE)



set(EXECUTABLE_OUTPUT_PATH ${gitlfs-gui-by-sea5kg_SOURCE_DIR})
set(QTCORE_LIBRARIES ${Qt5Core_LIBRARIES})
include_directories(${Qt5Core_INCLUDE_DIRS})

# Sources

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "src")
list (APPEND WSJCPP_INCLUDE_DIRS "src/interfaces")

# main
list (APPEND WSJCPP_SOURCES "src/main.cpp")
list (APPEND WSJCPP_SOURCES "src/mainwindow.cpp")

include_directories(${WSJCPP_INCLUDE_DIRS})

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

add_executable (gitlfs-gui-by-sea5kg ${WSJCPP_SOURCES} resources.qrc)

qt5_use_modules(gitlfs-gui-by-sea5kg Core Gui Widgets)
target_link_libraries(gitlfs-gui-by-sea5kg ${WSJCPP_LIBRARIES} )

install(
    TARGETS
        gitlfs-gui-by-sea5kg
    RUNTIME DESTINATION
        ${CMAKE_INSTALL_PREFIX}/bin
)
