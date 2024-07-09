cmake_minimum_required(VERSION 3.5.0)
project(Obschalka-server VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 11)

include_directories(includes)

find_package(Qt5 COMPONENTS Core WebSockets REQUIRED)

if(Qt5_FOUND)
    set(SOURCES
        sources/websocket_server.cpp
    )

    set(HEADERS
        includes/websocket_server.h
    )

    qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

    add_library(WebSocketServer ${SOURCES} ${MOC_SOURCES})
    target_link_libraries(WebSocketServer Qt5::Core Qt5::WebSockets)
else()
    message(FATAL_ERROR "Qt5 not found!")
endif()

add_executable(obschalka_server sources/main.cpp)
target_link_libraries(obschalka_server WebSocketServer)
