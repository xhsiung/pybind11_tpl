cmake_minimum_required(VERSION 2.8)

project(example)

#apt install python3.5-dev
find_package(PythonLibs 3 REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#git clone 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/pybind11/include)

SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -O3 -fPIC")

SET(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/example.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
#add_executable( ${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${PYTHON_LIBRARIES})


#libexample.so --> example.so
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES PREFIX "")
install(TARGETS ${PROJECT_NAME}  DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/example)
