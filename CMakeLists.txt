cmake_minimum_required(VERSION 3.14)
project(CS8_FinalProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Bar.cpp Bar.h Box.cpp Box.h Grid.cpp Grid.h SelectionSort.cpp SelectionSort.h GridBox.cpp GridBox.h Delay.cpp Delay.h Menu.cpp Menu.h)
add_executable(CS8_FinalProject ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(CS8_FinalProject sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
