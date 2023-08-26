cmake_minimum_required(VERSION 3.12)
project(SDLGame)  # Replace "YourProjectName" with your project's name

# Set the path to the SDL library
set(SDL2_PATH ${PROJECT_SOURCE_DIR}/lib/SDL2/)

# Include SDL CMake modules to find SDL2
list(APPEND CMAKE_MODULE_PATH ${SDL2_PATH}/cmake/SDL2)

# Find the SDL2 library
find_package(SDL2 REQUIRED)

# Add your project's source files here
set(SOURCE_FILES
        main.cpp
        # Add your other source files here
        )

# Create the executable for your project
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link the SDL2 library to your project
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)