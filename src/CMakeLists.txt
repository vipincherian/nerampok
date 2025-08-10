cmake_minimum_required(VERSION 3.20)
project(nerampok)

# set(wxWidgets_ROOT_DIR "/media/data/dev/lib/cpp/wx/3.3.1/")
# set(wxWidgets_LIB_DIR "/media/data/dev/lib/cpp/wx/3.3.1/buildgtk/lib/")
# set(wxWidgets_CONFIG_EXECUTABLE "/media/data/dev/lib/cpp/wx/3.3.1/buildgtk/wx-config")
# set(wxWidgets_CONFIG_EXECUTABLE "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../lib/cpp/wx/1.3.1/buildgtk/wx-config")

# message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
# message(PROJECT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

#find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

# List source files
set(SOURCES
    main.cpp
    controller.cpp
    frame.cpp
    constants.cpp
    preferences.cpp
    preferencesreader.cpp
    utils.cpp
    clockcontroller.cpp
    clockpanel.cpp
    containerpanel.cpp
    artprovider.cpp
    stoppedclock.cpp
    playingclock.cpp
    pausedclock.cpp
    alertingclock.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})
