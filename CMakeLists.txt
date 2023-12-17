# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(Pong)

# Add your source files
set(SOURCE_FILES
    src/main.cpp
    src/ball.cpp
    src/paddle.cpp
)

# Add executable target
add_executable(pong ${SOURCE_FILES})
