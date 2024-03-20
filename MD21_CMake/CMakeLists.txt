cmake_minimum_required(VERSION 3.29)
project(Labyrinth)
add_subdirectory(src/LabyrinthLib)
add_executable(labyrinthExecutable src/MD21.cpp)
target_link_libraries(labyrinthExecutable LabyrinthLib)

#boost
set(BOOST_ROOT "C:/Projects/VisualStudio/RTU(2023-2024)/MD21_CMake/src/BoostLib/boost_1_84_0")
find_package(Boost 1.84 COMPONENTS program_options)
target_link_libraries(labyrinthExecutable Boost::program_options)