cmake_minimum_required(VERSION 2.8.12)
project(XmlIO)

find_package(Qt5
COMPONENTS
  Core
  Xml
)

file(GLOB_RECURSE Cppfiles "*.cpp")
foreach(file ${Cppfiles})
  get_filename_component(name ${file} NAME_WE)

  message(STATUS "\t[add_executable] ${file}")
  add_executable(${name} ${file})
  target_link_libraries(${name} Qt5::Core Qt5::Xml)

  set_target_properties(${name} PROPERTIES FOLDER ${PROJECT_NAME})
endforeach()