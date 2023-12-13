# Pong Game Readme

This is a simple implementation of the classic Pong game using C++ and the Visual Studio IDE (2022). The game utilizes the console for rendering and keyboard input.

## Getting Started

To run the game, follow these steps:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/josegt96/Pong
   ```

2. **Open Project in Visual Studio:**
   - Open Visual Studio 2022.
   - Choose `Open a project or solution` and select the `pong-game.sln` file.

3. **Build and Run:**
   - Build the solution by pressing `Ctrl + Shift + B`.
   - Run the game by pressing `F5` or clicking the "Start Debugging" button.

## Controls

- Player 1 (Left Paddle):
  - Move Up: `w`
  - Move Down: `s`

- Player 2 (Right Paddle):
  - Move Up: `i`
  - Move Down: `k`

- Quit the game: `q`

## Gameplay

- The game starts with the ball moving randomly.
- Use the paddle controls to prevent the ball from passing your side.
- If the ball passes your paddle, the opponent scores a point.
- The game continues until you choose to quit (`q`).

## Code Structure

- `cBall`: Class representing the ball in the game.
- `cPaddle`: Class representing a paddle.
- `cGameManager`: Class managing the game logic, including scoring, drawing, and input handling.
- `main()`: The entry point of the program, creating an instance of `cGameManager` and running the game loop.

## Development Environment

- Language: C++
- IDE: Visual Studio 2022

## Acknowledgments

- This game was created as a learning project and is based on classic Pong gameplay.

Feel free to explore, modify, and extend the code for your own learning and enjoyment. If you have any questions or improvements, please open an issue or submit a pull request. Enjoy playing Pong!
