/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:27:15 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/07 13:08:21 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

bool	check_all_sprite_load(t_game *game)
{
	if (check_init_successfull(&game->player_idle) == false)
		return (print_error("Error\nAnim player idle failed to load"));
	if (check_init_successfull(&game->player_run) == false)
		return (print_error("Error\nAnim player run failed to load"));
	if (check_init_successfull(&game->player_jump) == false)
		return (print_error("Error\nAnim player jump failed to load"));
	if (check_init_successfull(&game->player_fall) == false)
		return (print_error("Error\nAnim player fall failed to load"));
	if (check_init_successfull(&game->player_hit) == false)
		return (print_error("Error\nAnim player hit failed to load"));
	if (check_init_successfull(&game->collectible) == false)
		return (print_error("Error\nCollectible failed to load"));
	if (check_init_successfull(&game->enemy_idle) == false)
		return (print_error("Error\nAnim enemy idle failed to load"));
	if (check_init_successfull(&game->enemy_attack) == false)
		return (print_error("Error\nAnim enemy attack failed to load"));
	if (check_init_successfull(&game->bubble) == false)
		return (print_error("Error\nAnim bubble failed to load"));
	if (check_init_successfull(&game->trail) == false)
		return (print_error("Error\nAnim trail failed to load"));
	return (true);
}
