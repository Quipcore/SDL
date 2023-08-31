cmake_minimum_required(VERSION 3.25)
project(SDLGame)

set(CMAKE_CXX_STANDARD 23)

set(SDL2_DIR ${CMAKE_SOURCE_DIR}/lib/SDL2/x86_64-w64-mingw32)
set(SDL2_INCLUDE_DIR ${SDL2_DIR}/include/SDL2)
set(SDL2_LIB_DIR ${SDL2_DIR}/bin)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})
link_directories(${SDL2_LIB_DIR}/../lib)

add_executable(${PROJECT_NAME} main.cpp tutorials/01_helloSDL/helloSDL.cpp tutorials/02_drawImage/drawImageSDL.cpp chess/chess.cpp)

include_directories(chess)
add_subdirectory(chess)

target_link_libraries(${PROJECT_NAME} SDL2)

# Set the output directory for the executable
set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

