cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set (CMAKE_CXX_STANDARD 20)

project(wordle-helper)

add_executable(${PROJECT_NAME})

include(FetchContent)
FetchContent_Declare(
    cli11
    QUIET
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.6.2
)
FetchContent_MakeAvailable(cli11)
target_link_libraries(${PROJECT_NAME} PRIVATE CLI11::CLI11)

add_subdirectory(src)
