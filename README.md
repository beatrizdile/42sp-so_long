<h1 align=center>
  42 Cursus
 </h1>
<h2 align=center>
  so_long

  ![so_long Logo](https://game.42sp.org.br/static/assets/achievements/so_longm.png)

  </h2>

## Description

**so_long** is a simple 2D game project developed in C as part of the curriculum. The objective of the game is to collect all the collectibles (items) on the map and reach the exit door while avoiding obstacles and enemies. The game uses the **minilibx** (a minimal X-Window library) to handle graphics and inputs.

This project aims to reinforce concepts related to graphics, handling inputs, and basic game development using C and X-Window system.

## Installation

Before proceeding with the installation, make sure you have the following dependencies installed:

- GCC (GNU Compiler Collection)
- X11 libraries and development headers
- CMake (optional)

Follow the steps below to install and run the game:

1. Clone the repository to your local machine:

```bash
git clone git@github.com:beatrizdile/42sp-so_long.git
```

2. Compile the game:
```bash
make
```

3. Execute with a valid map:
```bash
./so_long maps/map1.ber
```

You can replace maps/map1.ber with any valid map file of your choice. The game will load the specified map, and you can start playing.

### Game Rules
- The player starts at the player spawn position ('P') and has to collect all the collectibles ('C') on the map.
- Avoid enemies ('X') and obstacles ('1') on the map, as touching them will result in a game over.
- The exit door ('E') will only open once all the collectibles are collected.
- Reach the exit door to win the game.

## Controls

Use the following controls to navigate the player character:

- W or Up Arrow: Move the player up.
- S or Down Arrow: Move the player down.
- A or Left Arrow: Move the player left.
- D or Right Arrow: Move the player right.
- ESC or Cross Button (X): Close the game.

## Map Format

Maps for the game are stored in plain text files with the extension '.ber'. Each character represents a specific element on the map:

- 0: Empty space (floor)
- 1: Wall (obstacle)
- P: Player spawn position
- C: Collectible item
- E: Exit door
- N: Enemy spawn position (optional)

Example valid map:

```text
1111111
1P0C0E1
1111111
```

## Resources

- [minilibx](https://github.com/42Paris/minilibx-linux) - The minimal X-Window library used for graphics and inputs.


















