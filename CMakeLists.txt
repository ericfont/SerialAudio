# CMakeLists.txt
cmake_minimum_required(VERSION 3.0)
project(test)

add_subdirectory(lib/serial)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE src/main.cpp)

target_include_directories(${PROJECT_NAME}
  PUBLIC "lib/serial/include"
)

target_link_directories(${PROJECT_NAME}
  PUBLIC lib/serial/src
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC serial
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

