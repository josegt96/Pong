# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(Pong)

# Add your source files
set(SOURCE_FILES
    src/main.cpp
    src/entity/ball/ball.cpp
    src/entity/paddle/paddle.cpp
    src/entity/pong/pong.cpp
)
# Add executable target
add_executable(pong ${SOURCE_FILES})
# Find SDL2
find_package(SDL2 REQUIRED)
# Include SDL2 headers
include_directories(${SDL2_INCLUDE_DIRS})
# Link against SDL2
target_link_libraries(pong ${SDL2_LIBRARIES})
