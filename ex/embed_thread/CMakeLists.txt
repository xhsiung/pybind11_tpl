cmake_minimum_required(VERSION 3.0)

project(my)

#git clone https://github.com/pybind/pybind11.git
add_subdirectory( pybind11 )
find_package(Threads REQUIRED)

SET(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp

)

#add_library(${PROJECT_NAME} SHARED ${SOURCES})
add_executable( ${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE pybind11::embed  ${CMAKE_THREAD_LIBS_INIT})
