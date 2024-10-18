# So_Long

## Screenshots

![Screenshot](https://github.com/Vpekdas/so_long/assets/135771100/8ca41586-b4c1-41f3-b854-1607b83bcf2e)
![Screenshot2](https://github.com/Vpekdas/so_long/assets/135771100/3ec73123-3419-4cf2-81a0-b0f8e8eb7a60)
![Screenshot3](https://github.com/Vpekdas/so_long/assets/135771100/0c883d22-1085-42be-896a-f5845a53cc85)
![Screenshot4](https://github.com/Vpekdas/so_long/assets/135771100/c18fc6bb-f28d-40ca-bcce-8cb55505b94e)
![Screenshot5](https://github.com/Vpekdas/so_long/assets/135771100/51146d3c-1179-4dee-b57a-fd1e0df6dddd)

https://github.com/Vpekdas/so_long/assets/135771100/98245c2f-3c4a-484f-ad12-3508be37d7b3

# Table of Contents
1. [Description](#description)
2. [Installation Instructions](#installation-instructions)
3. [Usage Instructions](#usage-instructions)
4. [Key Features](#key-features)
5. [Contribution Guidelines](#contribution-guidelines)
6. [Acknowledgments](#acknowledgments)
7. [License Information](#license-information)
8. [Contact Information](#contact-information)
9. [Project Development](#project-development)

## Description

So_Long is a 2D game development project that is part of the 42 curriculum and is implemented in C. The primary goal of this project is to create an engaging and interactive 2D game that can provide a fun gaming experience.

The game is designed with a focus on the fundamentals of game development, including game loops, rendering, user input handling, and collision detection. The challenge lies in creating a game that is not only fun to play but also well-structured and efficient in terms of performance.

This project is a great opportunity to delve deeper into the workings of game development and enhance your knowledge of programming in C. It tests your understanding of various programming concepts, including data structures, algorithms, and memory management.

## Installation Instructions

1. **Check Operating System**: This game is designed to run on Linux systems. Ensure you are running a compatible Linux distribution before proceeding with the installation.

2. **Install Necessary Packages**: Certain packages are required to run the game. You can install them using your distribution's package manager. For example, on Ubuntu, you can use the following command:

- X11 include files (package xorg)
- XShm extension must be present (package libxext-dev)
- Utility functions from BSD systems - development files (package libbsd-dev)

```bash
sudo apt install xorg libxext-dev libbsd-dev
```

3. **Install a C compiler**: If you don't already have a C compiler installed, you will need one to build and use this library. You can install the [GCC compiler](https://gcc.gnu.org).

- On a Linux machine, use the package manager for your distribution. For example, on Ubuntu:
```bash
sudo apt install build-essential
gcc --version
```

## Usage Instructions

1. **Compile the game**: Navigate to the project directory and compile the game using the `make` command:
```bash
make
```

This will create an executable file named so_long.

2. Select a map: Choose a map from the maps folder. Note the name of the map file.

3. Start the game: You can start the game by running the following command in your terminal:
```bash
./so_long maps/map.ber
```

4. Controls
- `W` or `↑`: Jump
- `A` or `←`: Move left
- `S` or `↓`: Dash down
- `D` or `→`: Move right
- `SPACE`: Throw a bomb
- `ESC` or click the `cross` in the top-right corner: Exit the game

## Key Features

### Introduction and Project Choice:
Firstly, I chose to code a 2D platformer game, finding it more enjoyable to play and a bit different from what other students at 42 were doing. I'll briefly explain the challenges I faced during this project.

### Understanding minilibx and Developing a Game Engine:
Understanding how the minilibx library works was the initial step. This involved learning how to create a window, establish a game loop, and close the window, among other things. Fortunately, I had some knowledgeable peers who helped me grasp the basics. However, I quickly realized that minilibx wouldn't be sufficient for creating an engaging game, leading us to develop a small game engine.

### Rendering Pixels and Converting Sprites:
The next step was to render pixels and find appealing sprites, which had to be converted to XPM format as minilibx only supports this format.

### Implementing Collision Detection and Handling Large Maps:
Once I had a grasp on that, I needed to implement collision detection. Thanks to my peers, I learned a useful calculation for detecting collisions between two 2D boxes. Then, I had to handle scenarios where the map was larger than the window. While some students chose not to start the game in such cases (which is perfectly acceptable), I decided to code a camera centered on the player to address this issue.

### Learning New Concepts and Enhancing the Game:
As I progressed, many talented individuals shared their ideas for enhancing the game. I learned about concepts like parallax and "vignette" (darkening the corners of the game to simulate being in a darker place, like a cave). I also learned how animations work - they're essentially a series of images displayed frame by frame, creating the illusion of movement. To increase the game's difficulty, I added enemies capable of dodging (someone even said my game resembles Dark Souls!).

### Adding Particles and Discovering Randomization:
Later, I learned about particles and decided to add bubbles popping from the bottom. I also discovered a handy function for randomization. Importantly, all of this was accomplished without using any forbidden functions.

### Developing a Finishability Algorithm:
Finally, we had to develop an algorithm to check if the game is finishable. This was the part that intimidated me the most. Thankfully, the community at 42 was incredibly supportive, helping me code a modified flood fill algorithm that incorporated gravity and jump conditions.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* The technique I used for printing pixels is as follows:
We write pixels into a buffer. An XPM file is essentially a `char **` array, where each character represents a color. We parse the XPM file, where each index is a color, and copy this pixel to our game screen buffer. We need to ensure that the sum of the screen index and image index is within our screen. If not, it will cause a segmentation fault because we would be trying to add a pixel outside of our buffer. By doing this, we can ensure that if, for example, an enemy is visible, we won't print its pixel.

* In reality, this code is quite straightforward. To simulate a camera effect, we subtract the position of our player from everything else. This creates the illusion of screen scrolling.
  
* Another advantage is that we can handle transparency. This is achieved by using the color black (0xFF000000) as a stand-in for transparency in the image data. When the code encounters a pixel of this color, it simply skips over it without drawing anything, allowing whatever is behind it to show through. This creates the effect of transparency.
```C
void	draw_sprite(t_game *game, t_img *img, int x, int y)
{
    const int		offx = -game->play.x + WIN_W / 2 - 64 * SCALE / 2;
    const int		offy = -game->play.y + WIN_H / 2 - 64 * SCALE / 2;
    int				i;
    int				j;
    unsigned int	color;

    i = 0;
    while (i < img->width * SCALE)
    {
        j = -1;
        while (++j < img->height * SCALE)
        {
            if (j + y + offy < 0 || j + y + offy >= game->screen->height
                || i + x + offx < 0 || i + x + offx >= game->screen->width)
                continue ;
            color = ((int *)img->data)[(int)
                (j / SCALE) *img->width + (int)(i / SCALE)];
            if (color == 0xFF000000)
                continue ;
            ((int *)game->screen->data)[(y + j + offy)
                * game->screen->width + (x + i + offx)] = color;
        }
        i++;
    }
}
```

* Let's take a quick look at the main function, and then we'll delve into the basic features that I've used for various mechanics.

* First, I initialize the minilibx settings, such as the mlx pointer and the window. Then, I perform several checks on the map to ensure it's valid and there are no memory allocation errors.

* Next, I check my character's settings to ensure they have a correct position, etc. Then, I load all my sprites. If all these things are okay, I can launch my game and start using loop hooks. The idea behind these is to create "hooks", which dictate what to do when you press a button or click on a cross.

* Finally, we have the mlx loop, which is a sort of infinite loop. To exit this loop, you need to call the function mlx_end_loop (I call this function when the player dies or when they have collected everything and exited correctly).
```C
int	main(int ac, char **av)
{
	t_game		game;

	if (ac != 2)
	{
		ft_putstr_fd(RED"Error\n🗺️ You need to give one map🗺️\n", 2);
		return (-1);
	}
	game = (t_game){0};
	if (init_mlx_settings(&game, av) == -1)
		return (-1);
	if (init_player_and_map(&game) == -1)
		return (free_if_error_init_map_player(&game));
	if (check_map_character_overall(&game) == false)
		return (free_if_error_map(&game));
	init_sprite(&game);
	if (check_all_sprite_load(&game) == false)
		return (free_if_error_sprites(&game));
	mlx_loop_hook(game.mlx, update, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_pressed, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_released, &game);
	mlx_hook(game.win, DestroyNotify, 0, close_game, &game);
	mlx_loop(game.mlx);
	free_if_no_error(&game);
	display_end_message(&game);
}
```

* The next crucial component is the game loop, which is the function called every frame. I won't delve into the details, but I've tried to organize it as clearly as possible.

* In general, I reset the x velocity each time to prevent sliding. Next, I detect which key the player has pressed and interpret it accordingly. Then, I add gravity; if the player isn't colliding with anything, I apply gravity on the Y axis. 

* Afterwards, I check if the player is colliding with collectibles or doors, and then update their movement. If there's a collision, I adjust their position. 

* Next, I draw the background and walls, and update the animations of the player, enemies, particles, etc. 

* Finally, I display the buffer where each pixel has been manually placed. The idea is to position all screen pixels according to my XPM image and their positions, and then display this buffer. The buffer is actually the game window. 

* Lastly, I display the HUD.
```C
int	update(t_game *game)
{
	t_box		player_box;

	game->frame_count++;
	if (game->play.health == 0)
		close_game(game);
	game->play.velocity_x = 0;
	detect_key(game);
	player_box = player_box_x_y_off_below(game);
	if (!collide_with_map(player_box, game))
		game->play.velocity_y += 18 * 0.016;
	player_box = player_box_y_off(game, game->play.velocity_y);
	update_collide(game, player_box);
	update_move(game);
	draw_background(game);
	draw_map(game->map, game);
	update_animation(game);
	update_particle_and_background(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	display_hud(game);
	return (0);
}

void	update_collide(t_game *game, t_box player_box)
{
	collide_with_collectible(player_box, game);
	collide_with_exit_chest(player_box, game);
}

void	update_move(t_game *game)
{
	move_player(game, game->play.velocity_x, game->play.velocity_y);
	move_enemy(game, game->enemy_list);
}

void	update_animation(t_game *game)
{
	update_anim_player(game);
	update_anim_enemy(game);
	update_anim_collectible(game->map, game);
	update_bomb(game);
	update_anim_explotion(game);
}

void	update_particle_and_background(t_game *game)
{
	draw_sprite_background(game, game->sprites[FOREGROUND], game->fg_scroll);
	update_anim_bubble(game);
	update_anim_trail(game);
	draw_vignette(game);
}
```

* Function to initialize minilibx settings
```C
int	init_mlx_settings(t_game *game, char **av)
{
    // Initialize minilibx and check for errors
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        ft_putstr_fd(RED"Error\n❌the mlx pointer is NULL❌\n", 2);
        return (-1);
    }

    // Create a new window with the specified width and height
    game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "so_long");

    // Create a new image for the screen
    game->screen = mlx_new_image(game->mlx, WIN_W, WIN_H);

    // Assign the map path from the command line arguments
    game->map_path = av[1];

    return (0);
}
```

* For collison part, i m creating bounding box in 2D, i m using the same logic for my collectible, enemy collision or bomb collision.

* This function check if 2 bounding box collides in a 2D.
```C
bool	collide(t_box player, t_box object)
{
	return (player.pos_x < object.pos_x + object.width
		&& player.pos_x + player.width > object.pos_x
		&& player.pos_y < object.pos_y + object.height
		&& player.pos_y + player.height > object.pos_y);
}
```

* This function create a boundix box for a wall.
```C
t_box	map_box_scale(int x, int y)
{
	t_box	box;

	box.pos_x = x * SPRITE_SIZE * SCALE;
	box.pos_y = y * SPRITE_SIZE * SCALE;
	box.width = SPRITE_SIZE;
	box.height = SPRITE_SIZE;
	return (box);
}
```
* This function check every frame if there is a collision between player and map.
```C
bool	collide_with_map(t_box player, t_game *game)
{
	int		x;
	int		y;
	t_box	entity_box;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			entity_box = map_box_scale(x, y);
			if (game->map[y][x] && game->map[y][x] == '1'
				&& collide(player, entity_box) == true)
				return (true);
			y++;
		}
		x++;
	}
	return (false);
}
```

* These two functions handle collision detection on the x and y axes separately. This allows movement along one axis even if there's a collision on the other, preventing the player from getting stuck. The approach involves predicting a bounding box with velocity, which helps determine if the next move will result in a collision. If a collision is predicted, the velocity is reduced until it reverses direction. The direction of movement is stored: a positive velocity indicates rightward movement, so the velocity is decreased until it becomes negative, at which point it's set to zero. This new velocity is then added to the player's position. As a result, the player doesn't move because their velocity has been reduced to zero, preventing future collisions.
```C
void	adjust_velocity_x(t_game *game, float vx)
{
	const float	precision = 0.5;
	const bool	vx_positive = vx > 0;
	bool		collide_x;

	collide_x = collide_with_map(player_box_x_off(game, vx), game);
	while (((vx_positive && vx > 0) || (!vx_positive && vx < 0)) && collide_x)
	{
		if (vx_positive)
			vx -= precision;
		else if (!vx_positive)
			vx += precision;
	}
	if ((vx_positive && vx < 0) || (!vx_positive && vx > 0))
		vx = 0;
	game->play.velocity_x = vx;
	game->play.x += vx;
}

void	adjust_velocity_y(t_game *game, float vy)
{
	const bool	vy_positive = vy > 0;
	bool		collide_y;
	bool		should_collide;
	const float	precision = 0.5;

	collide_y = collide_with_map(player_box_y_off(game, vy), game);
	should_collide = collide_y;
	while (collide_y && fabs(vy) > precision)
	{
		collide_y = collide_with_map(player_box_y_off(game, vy), game);
		vy -= precision * (vy_positive * 2 - 1);
	}
	if (should_collide)
	{
		if (fabs(vy) <= precision)
			vy = 0;
		game->play.velocity_y = 0;
	}
	game->play.y += vy;
}
```

* Again, I won't go into detail here, but I encourage you to directly click on the .c file if you want to analyze how I implemented a feature in more depth. You can also ask me any questions if something isn't clear. I've tried to name my files, structures, and functions clearly. The last thing I want to discuss is the finishability algorithm. It's the famous flood fill algorithm, which attempts to fill a map. If there are no collectibles and doors on the map, it means that a player can finish the game.

* I use recursion to call this function from every position a player can reach. The algorithm has two modes: either the player can jump because they haven't reached the maximum height they can achieve, or they are falling, so they can move left or right after jumping. To avoid segmentation faults and unnecessary movements, I ensure that the algorithm doesn't go beyond the map boundaries, spawn inside a wall, or revisit a location it has already been to.
```C
void	pathfinding(int x, int y, int jump, t_game *game)
{
	int	max_jump;

	max_jump = 3;
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return ;
	if (game->map_copy.map[y][x] == '.' || game->map_copy.map[y][x] == '1')
		return ;
	if (game->map_copy.map[y][x] == 'C')
		game->accessible_collectibles++;
	if (game->map_copy.map[y][x] == 'E')
		game->accessible_door++;
	game->map_copy.map[y][x] = '.';
	if (jump <= 0)
		fall(x, y, max_jump, game);
	else
		jmp(x, y, jump, game);
}
```
## Acknowledgments

Special thanks to the following individuals and assets for their contributions to this project:

- [FirePh0enix](https://github.com/FirePh0enix): Thank you for explaining the basics of sprite drawing, key detection, collision calculation, gravity management, parallax effects, and player camera coding.
- [Fidwig](https://github.com/fidwig): Special thanks for coding the vignette, optimizing falling collision, and initiating pathfinding with the max jump factor.
- [ForAbby-X](https://github.com/ForAbby-X): Gratitude for providing references in 2D game development and sharing ideas to enhance the game's immersion.
- [Ludenc](https://ludenc.itch.io/): Providing the Cave background and tileset.
- [Pixel Frog](https://pixelfrog-assets.itch.io/): Supplying player, enemy, and bomb animated textures.
- [Totuslotus](https://totuslotus.itch.io/): Contributing animated coin textures.

## Contribution Guidelines

I welcome contributions from everyone. Here are some guidelines to follow:

1. **Fork the repository**: Start by forking the repository to your own GitHub account.

2. **Clone the repository**: Clone the forked repository to your local machine.
```bash
git clone https://github.com/Vpekdas/so_long.git
```

3. **Create a new branch**: Create a new branch for each feature or bug fix you're working on. Do not make changes directly on the master branch
```bash
git checkout -b your-branch-name
```

4. **Make your changes**: Make your changes in the new branch. Ensure your code follows the [norminette](https://github.com/42School/norminette).

5. **Commit your changes**: Commit your changes regularly with clear, descriptive commit messages.
```bash
git commit -m "Your commit message"
```

6. **Push your changes**: Push your changes to your forked repository on GitHub.
```bash
git push origin your-branch-name
```

7. **Create a pull request**: Go to your forked repository on GitHub and create a new pull request against the master branch.
Please note that this project has a code of conduct, and contributors are expected to adhere to it. Any contributions you make are greatly appreciated.

## License Information

This project is licensed under the [MIT License](LICENSE).

The MIT License is a permissive license that is short and to the point. It lets people do anything they want with your code as long as they provide attribution back to you and don’t hold you liable.

For the full license text, see the [LICENSE](LICENSE) file.

## Contact Information

If you have any questions, issues, or if you want to contribute, feel free to reach out to me:

- GitHub: [@Vpekdas](https://github.com/Vpekdas)
- Discord: Captain-Plouf#7811

## Project Development

### Development Process

The development of "so_long" started with a simple goal: to print a pixel on the screen. After learning the basics of the MiniLibX library and with the help of some friends, I was able to implement basic features like drawing a sprite. The rest of the features were developed independently, often by watching tutorials in other languages and adapting the concepts to C. The project was structured around various entities and features, with each one having its own dedicated file.

### Challenges and Solutions

The main challenges faced during the development of "so_long" were related to rendering characters and tiles correctly on the screen, handling collisions, correctly displaying sprites with necessary offsets, and coding animations and projectiles. Overcoming these challenges often involved watching basic tutorials and then translating the concepts into C. A lot of trial and error was involved, but this process was both fun and educational.

### Tools and Technologies Used

"So_long" was developed using C and the MiniLibX library. The game was built and tested on a linux machine.

### Lessons Learned

The development of "so_long" provided a deep understanding of how basic games work, including concepts like animation, collision detection, and camera control. It also sparked an interest in game engines and admiration for the complexity and sophistication of modern games.

### Future Plans

While there are currently no plans to update "so_long", the experience of developing it has led to a new project using the Godot engine. The journey from coding a simple game in C to exploring a full-fledged game engine has been exciting and rewarding.

### Current Status

The project is currently complete and not in active development. However, maintenance and updates will be done as needed.

### Known Issues

There are currently no known issues. If you find a bug, please report it in the [issue tracker](https://github.com/Vpekdas/so_long/issues).

### Contributing

Contributions are always welcome! See the [Contribution Guidelines](#contribution-guidelines) for more information.
