cmake_minimum_required(VERSION 3.25)
project(SDLGame)

set(CMAKE_CXX_STANDARD 23)

set(SDL2_INCLUDE_DIR lib/SDL2/include)
set(SDL2_LIB_DIR lib/SDL2/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} -lSDL2main -lSDL2)