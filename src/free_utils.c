/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:54:28 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/10 15:26:01 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_anim_sprite(t_anim *anim, t_game *game)
{
	int	i;

	if (!anim)
		return ;
	i = 0;
	while (i < anim->frame_count)
	{
		if (anim->img[i])
		{
			mlx_destroy_image(game->mlx, anim->img[i]);
			anim->img[i] = NULL;
		}
		i++;
	}
	free(anim->img);
}

void	free_all_sprites(t_game *game)
{
	int	i;

	i = 0;
	free_anim_sprite(&game->player_idle, game);
	free_anim_sprite(&game->player_run, game);
	free_anim_sprite(&game->player_jump, game);
	free_anim_sprite(&game->player_fall, game);
	free_anim_sprite(&game->player_hit, game);
	free_anim_sprite(&game->collectible, game);
	free_anim_sprite(&game->enemy_idle, game);
	free_anim_sprite(&game->enemy_attack, game);
	free_anim_sprite(&game->bubble, game);
	free_anim_sprite(&game->trail, game);
	free_anim_sprite(&game->explotion, game);
	while (i < NUM_SPRITES)
	{
		mlx_destroy_image(game->mlx, game->sprites[i]);
		i++;
	}
	free(game->sprites);
}

void	free_map(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i])
		{
			free(game->map[i]);
			game->map[i] = NULL;
		}
		i++;
	}
	free(game->map);
}

void	free_copy_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_copy.map_height)
	{
		if (game->map_copy.map[i])
		{
			free(game->map_copy.map[i]);
			game->map_copy.map[i] = NULL;
		}
		i++;
	}
	free(game->map_copy.map);
}

void	free_list_bubble(t_node_bubble *list)
{
	t_node_bubble	*tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
