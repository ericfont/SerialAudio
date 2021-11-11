# CMakeLists.txt
cmake_minimum_required(VERSION 3.0)
project(SerialAudio)

find_package(Boost 1.77.0 REQUIRED) #Boost::config Boost::bind Boost::asio)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
	Boost::boost
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

