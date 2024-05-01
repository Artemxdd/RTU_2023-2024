cmake_minimum_required(VERSION 3.22.1)
project(MD25)
file(GLOB headers "main/h/*.h")
file(GLOB sources "main/C/*.C")
add_executable(MD25Exec ${sources} ${headers})

target_include_directories(FilesHandlingLib PUBLIC)
target_link_libraries(FilesHandlingLib)
