cmake_minimum_required(VERSION 3.0)
project(Nibbler VERSION 1.0 LANGUAGES CXX)

# Set default build type to "Release" if none is specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
endif()

set(CMAKE_C_STANDARD 11)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

# Adding Raylib
FetchContent_Declare(
	raylib
	GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
	GIT_TAG "5.0"
	GIT_PROGRESS TRUE
	GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(raylib)

# Adding SDL
FetchContent_Declare(
	SDL2
	GIT_REPOSITORY "https://github.com/libsdl-org/SDL"
	GIT_TAG "release-2.30.8"
	GIT_PROGRESS TRUE
	GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(SDL2)

# Adding SFML
FetchContent_Declare(
	SFML
	GIT_REPOSITORY "https://github.com/SFML/SFML"
	GIT_TAG "2.6.1"
	GIT_PROGRESS TRUE
	GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(SFML)

# Adding our source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp") # Define PROJECT_SOURCES as a list of all source files
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/") # Define PROJECT_INCLUDE to be the path to the include directory of the project

# Declaring our executable
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML)

# Setting ASSETS_PATH
# target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="./assets") # Set the asset path macro in release mode to a relative path that assumes the assets folder is in the same directory as the game executable

# You'll may be need to install the following dependencies for the SFML:
#	- libasound2-dev
#	- libgl1-mesa-dev
#	- libudev-dev
#	- libopenal-dev
#	- libvorbis-dev
#	- libflac-dev