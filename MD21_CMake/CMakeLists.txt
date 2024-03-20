cmake_minimum_required(VERSION 3.29)
project(Labyrinth)
add_subdirectory(src/LabyrinthLib)
add_executable(labyrinthExecutable src/MD21.cpp)
target_link_libraries(labyrinthExecutable LabyrinthLib)

#boost
set(BOOST_ROOT "C:/Program Files/boost/boost_1_84_0/boost_1_84_0")
find_package(Boost 1.84 COMPONENTS program_options)
target_link_libraries(labyrinthExecutable Boost::program_options)