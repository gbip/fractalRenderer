cmake_minimum_required(VERSION 3.5)
project(fractalRenderer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

#GTK3 Stuff
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})
#SFML Stuff

set(SOURCE_FILES main.cpp Math/Complex.h Window.cpp Window.h Fractal.cpp Fractal.h Math/MathHeader.h Math/BiDimensionnalArray.cpp Math/BiDimensionnalArray.h)


add_executable(fractalRenderer ${SOURCE_FILES})
target_link_libraries(fractalRenderer sfml-system sfml-window sfml-graphics ${GTK3_LIBRARIES} ${SFML_LIBRARIES})
