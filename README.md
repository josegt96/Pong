# Pong Game

## Overview

This project implements a simple Pong game using C++ and the SDL2 library. The game consists of a ball and two paddles, and the objective is to score points by hitting the ball past the opponent's paddle.

## How to Build

To build the project, follow these steps:

1. Make sure `SDL2` and `CMAKE`  is installed on your system.

```bash
sudo pacman -S sdl2 cmake
```
2. Create a build directory and build the project `make`

```bash
mkdir build
cd build
cmake ..
make
```

## Run the Game

After building the project, run the executable:

```bash
./pong
```

This will generate the "pong" executable in the build directory.

## How to Play

- **Player 1:**
  - Move Up: W
  - Move Down: S

- **Player 2:**
  - Move Up: I
  - Move Down: K

- **Quit:**
  - Q

## Project Structure

The project is organized into three main classes:

- **Ball Class (`ball.h`):** Represents the ball in the Pong game.

- **Paddle Class (`paddle.h`):** Represents a paddle in the Pong game.

- **Game Manager Class (`main.cpp`):** Manages the game state, input, rendering, and logic.

## Dependencies

- [SDL2 Library](https://www.libsdl.org/)

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgments

Special thanks to the SDL2 development team for their contributions to the gaming community.

Enjoy playing Pong!