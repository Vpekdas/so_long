# so_long

## Screenshots

![Screenshot](https://github.com/Vpekdas/so_long/assets/135771100/8ca41586-b4c1-41f3-b854-1607b83bcf2e)
![Screenshot2](https://github.com/Vpekdas/so_long/assets/135771100/3ec73123-3419-4cf2-81a0-b0f8e8eb7a60)
![Screenshot3](https://github.com/Vpekdas/so_long/assets/135771100/0c883d22-1085-42be-896a-f5845a53cc85)
![Screenshot4](https://github.com/Vpekdas/so_long/assets/135771100/c18fc6bb-f28d-40ca-bcce-8cb55505b94e)
![Screenshot5](https://github.com/Vpekdas/so_long/assets/135771100/51146d3c-1179-4dee-b57a-fd1e0df6dddd)

https://github.com/Vpekdas/so_long/assets/135771100/98245c2f-3c4a-484f-ad12-3508be37d7b3

## Table of Contents
1. [Description](#description)
2. [Installation](#installation)
3. [Run](#run)
4. [Credits](#credits)
5. [Contributing](#contributing)
6. [License](#license)

## Description

so_long is a project from the 42 Common Core curriculum designed to introduce students to low-level graphics programming using the MiniLibX graphics API. The objective is to build a simple 2D game where the player must collect items and reach the exit while avoiding enemies.

As part of the 42 curriculum, this project comes with strict coding guidelines:
- The standard C library is forbidden, requiring the use of custom code for all tasks.
- A strict rule of 5 functions per file and 25 lines per function is enforced.
- There are restrictions such as no assignments on the same line and a focus on clean, maintainable code.

This project provides hands-on experience with low-level graphical programming and reinforces good coding practices under challenging constraints.

### Purpose

The goal of this game is to collect all the collectibles and defeat or avoid enemies to reach the exit safely.
Key features include:

- Gravity-based movement
- Collision solver for map and object interactions
- Smart enemies that:
    - Dodge projectiles
    - Track the player's position
    - Launch attacks
- Animated sprites for:
    - Player
    - Enemies
    - Collectibles
    - Projectiles and particles
- Parallax background for visual depth
- Interactive doors that open when all collectibles are gathered

## Controls

| **Controls** | **Actions** |
|:------------:|-------------|
| `W` or `↑` | Jump |
| `A` or `←` | Move Left |
| `S` or `↓` | Dash Down |
| `D` or `→` | Move Right |
| `Space` | Throw projectiles |
| `ESC` or click the `X` in the top-right corner | Exit the game |

### Technologies used

- C language.
- Make.

### Challenges and Future Features

The main challenges were learning how MiniLibX works, creating a window, drawing pixels and sprites, implementing a game loop and keyboard input, handling game physics like gravity and collisions, experimenting with visual effects such as parallax scrolling and cave darkening, and developing an algorithm to ensure that the map is completable.

I'm not planning to add new features.

## Installation

- Ensure you have a C compiler installed, such as [Clang](https://clang.llvm.org/) or [GCC](https://gcc.gnu.org/)
```bash
clang --version
gcc --version
```
- Ensure you have installed [Make](https://www.gnu.org/software/make/) to build the project
```bash
make --version
```

- Install Necessary Packages: Certain packages are required to run the game. You can install them using your distribution's package manager. For example, on Ubuntu, you can use the following command:

- X11 include files (package xorg)
- XShm extension must be present (package libxext-dev)
- Utility functions from BSD systems - development files (package libbsd-dev)

```bash
sudo apt install xorg libxext-dev libbsd-dev
```

Warning: This game can only work in Unix systems since the functions used and the minilib functions called needs X11, in windows you can install [WSL](https://learn.microsoft.com/fr-fr/windows/wsl/install) and install packages. In Macos, it wont works.

- Windows: You can install WSL (Windows Subsystem for Linux) and set up the necessary packages to run the game.
- MacOS: Unfortunately, the game won't work on macOS as it doesn't support the necessary X11 functions natively.

## Run

1. Build the project:
```bash
make
```

2. This will create a `./so_long` binary.

3. Run the program with the following arguments:

```bash
./so_long [maps]
```

### Map Customization

The maps for the game are stored in files with the .ber extension. These are essentially text files where the game’s layout and elements are defined. You can find our pre-configured maps in the assets/maps directory.

When creating a custom map, be sure to follow these rules to ensure proper functionality:

#### 1. Player Boundaries
Ensure that the player cannot go outside the map's boundaries. If the player can escape the map, the algorithm will refuse the map and display an error.

##### Map Layout:
- 1 Refers to walls in the map, which the player cannot pass through.
- 0 Refers to empty spaces where the player can walk.
- D: Refers to a door in the map. There must be only one in the map.
- C: Refers to collectibles. There must be at least one in the map.
- P: Refers to player. There must be only one in the map.

## Credits

Special thanks to the following individuals and assets for their contributions to this project:

- [FirePh0enix](https://github.com/FirePh0enix): Thank you for explaining the basics of sprite drawing, key detection, collision calculation, gravity management, parallax effects, and player camera coding.
- [Fidwig](https://github.com/fidwig): Special thanks for coding the vignette, optimizing falling collision, and initiating pathfinding with the max jump factor.
- [ForAbby-X](https://github.com/ForAbby-X): Gratitude for providing references in 2D game development and sharing ideas to enhance the game's immersion.
- [Ludenc](https://ludenc.itch.io/): Providing the Cave background and tileset.
- [Pixel Frog](https://pixelfrog-assets.itch.io/): Supplying player, enemy, and bomb animated textures.
- [Totuslotus](https://totuslotus.itch.io/): Contributing animated coin textures.

## Contributing

To report issues, please create an issue here:  [issue tracker](https://github.com/Vpekdas/so_long/issues).

If you'd like to contribute, please follow the steps outlined in [CONTRIBUTING.md](CONTRIBUTING.md).

## License

This project is licensed under the [MIT License](LICENSE).

### Third-Party Licenses

- **MiniLibX**, provided by École 42, is included in this project and is licensed under the [BSD 2-Clause License](minilibx-linux/README.md).  
  Please refer to the linked file for full license terms.
