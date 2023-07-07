## Snake Game

The Snake game was a simple console-based game implemented in C++. It involved controlling a snake to collect food and grow longer while avoiding collisions with its own body and the game borders.

### Functionality

- The game allowed the player to control the snake's movements using the keyboard inputs: ‘a’ for left,’d’ for right, ‘w’ for up, ‘s’ for down, and ‘e’ to quit the game.
- The snake's position and direction were updated automatically based on the player's input.
- The objective was to eat the food symbolised by the `F` character on the screen to increase the snake's length and score.
- Collisions with the snake's own body or the game borders resulted in game over.
- The game speed increases as the player achieves higher scores, making it more challenging.
- The highest score achieved was stored and loaded from a file named `high_score.txt`.
- The game displayes the score, game board, snake, food, and level information on the console.
- The game loop continuously rendered the game, handled player input, and updated the game state until the game over condition was met.

### Implementation

- The game was implemented using C++ and utilized standard libraries such as ‘<iostream>’, ‘<conio.h>’, ‘<windows.h>’, and ‘<fstream>’.
- The code consisted of various functions responsible for different aspects of the game.
- Global variables were used to keep track of the game state, including the snake's position, target position, score, tail coordinates, and current game level.
- Additional functions were defined for saving and loading the highest score from the ‘high_score.txt’ file.
- The game interface, including the game board, snake, food, score, and level, was rendered using the ‘box’ function.
- The game logic, such as updating the snake's position, checking for collisions, and increasing the score, was handled by the ‘Method’ function.
- Player input was captured by the ‘Input’ function, which changed the snake's direction accordingly.
- The game flow was controlled by the ‘main’ function, which initialised the game, entered the game loop, and controlled the game flow.
- The game speed was controlled using the ‘Sleep’ function from the ‘<windows.h>’ library.



