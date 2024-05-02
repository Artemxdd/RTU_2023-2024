cmake_minimum_required(VERSION 3.22.1)
project(MD25)
file(GLOB headers "main/h/*.h")
file(GLOB sources "main/C/*.C")
add_executable(MD25Exec ${sources} ${headers})

# Files Handling Library
add_subdirectory(FilesHandlingLib)
target_link_libraries(MD25Exec PUBLIC FilesHandlingLib)
target_include_directories(MD25Exec PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/FilesHandlingLib"
)
