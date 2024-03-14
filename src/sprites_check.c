/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:27:15 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/14 15:36:42 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdbool.h>

t_img	*load_sprite(void *img, char *filename)
{
	int	width;
	int	height;

	if (!img || !filename)
		return (NULL);
	return (mlx_xpm_file_to_image(img, filename, &width, &height));
}

bool	check_init_successfull(t_anim *anim)
{
	int	i;

	i = 0;
	while (i < anim->frame_count)
	{
		if (!anim->img[i])
			return (false);
		else
			i++;
	}
	return (true);
}

bool	check_init_success_tiles(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_SPRITES)
	{
		if (!game->sprites[i])
			return (false);
		else
			i++;
	}
	return (true);
}

bool	check_all_sprite_load(t_game *game)
{
	if (check_init_successfull(&game->player_idle) == false)
		return (print_error(RED"Error\n🚨Anim player idle failed to load🚨\n"));
	if (check_init_successfull(&game->player_run) == false)
		return (print_error(RED"Error\n🚨Anim player run failed to load🚨\n"));
	if (check_init_successfull(&game->player_jump) == false)
		return (print_error(RED"Error\n🚨Anim player jump failed to load🚨\n"));
	if (check_init_successfull(&game->player_fall) == false)
		return (print_error(RED"Error\n🚨Anim player fall failed to load🚨\n"));
	if (check_init_successfull(&game->player_hit) == false)
		return (print_error(RED"Error\n🚨Anim player hit failed to load🚨\n"));
	if (check_init_successfull(&game->collectible) == false)
		return (print_error(RED"Error\n🚨Collectible failed to load🚨\n"));
	if (check_init_successfull(&game->enemy_idle) == false)
		return (print_error(RED"Error\n🚨Anim enemy idle failed to load🚨\n"));
	if (check_init_successfull(&game->enemy_attack) == false)
		return (print_error(RED"Error\n🚨Anim enemy attack failed to load🚨\n"));
	if (check_init_successfull(&game->bubble) == false)
		return (print_error(RED"Error\n🚨Anim bubble failed to load🚨\n"));
	if (check_init_successfull(&game->trail) == false)
		return (print_error(RED"Error\nAnim trail failed to load🚨\n"));
	if (check_init_successfull(&game->explotion) == false)
		return (print_error(RED"Error\n🚨Anim explotion failed to load🚨\n"));
	if (check_init_success_tiles(game) == false)
		return (print_error(RED"Error\n🚨Tiles failed to load🚨\n"));
	return (true);
}
