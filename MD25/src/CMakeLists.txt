cmake_minimum_required(VERSION 3.22.1)
set(CMAKE_CXX_STANDARD 26)
project(MD25)
file(GLOB headers "main/h/*.h")
file(GLOB sources "main/C/*.C")
add_executable(MD25Exec ${sources} ${headers})

# Files Handling Library
add_subdirectory(FilesHandlingLib)
target_link_libraries(MD25Exec FilesHandlingLib)
target_include_directories(MD25Exec PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/FilesHandlingLib"
)

# Boost Library
find_package(Boost COMPONENTS program_options)
include_directories(${Boost_INCLUDE_DIRS}) 
target_link_libraries(MD25Exec ${Boost_LIBRARIES})
