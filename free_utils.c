/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:54:28 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/24 18:19:03 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_anim_sprite(t_anim anim, t_game *game)
{
	int	i;

	i = 0;
	while (i < anim.frame_count)
	{
		mlx_destroy_image(game->mlx, anim.img[i]);
		// free(anim.img[i]);
		i++;
	}
	free(anim.img);
}

void	free_all_sprites(t_game *game)
{
	free_anim_sprite(game->anim_player_idle, game);
	free_anim_sprite(game->anim_player_run, game);
	free_anim_sprite(game->anim_player_jump, game);
	free_anim_sprite(game->anim_player_fall, game);
	free_anim_sprite(game->anim_player_hit, game);
	free_anim_sprite(game->anim_enemy_idle, game);
	free_anim_sprite(game->anim_enemy_attack, game);
	free_anim_sprite(game->anim_bomb_on, game);
	free_anim_sprite(game->collectible, game);
}
