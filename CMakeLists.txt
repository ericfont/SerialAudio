cmake_minimum_required(VERSION 3.15)
project(SerialAudio VERSION 0.0.0)

#find_package(Boost 1.77.0 REQUIRED) #Boost::config Boost::bind Boost::asio)

add_subdirectory("lib/serial-port")

include(DPF/cmake/DPF-plugin.cmake)

dpf_add_plugin(${PROJECT_NAME}
  TARGETS jack lv2 vst2
  FILES_DSP
      main.cpp
#  FILES_UI
#      InfoExampleUI.cpp
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    simple-boost-serial-port
)
#add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE main.cpp)

target_include_directories(${PROJECT_NAME}
  PUBLIC
 	"."
       	"lib/serial-port/include"
#  PUBLIC "DPF/distrho"
#  PUBLIC "DPF/distrho/src"
)

target_link_directories(${PROJECT_NAME}
  PUBLIC "lib/serial-port"
)

#target_link_libraries(${PROJECT_NAME} PRIVATE
#	simple-boost-serial-port
#    distrho
#	#	Boost::boost
#	#        pthread
#)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

