cmake_minimum_required(VERSION 3.14)
project(SmartRoom LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(SmartRoom
    main.cpp
    Device.cpp
    Fan.cpp
    Light.cpp
    Room.cpp
    SmartHome.cpp
    SmartHomeController.cpp
)