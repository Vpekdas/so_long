/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:54:28 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/29 14:23:11 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_anim_sprite(t_anim *anim, t_game *game)
{
	int	i;

	i = 0;
	while (i < anim->frame_count)
	{
		mlx_destroy_image(game->mlx, anim->img[i]);
		anim->img[i] = NULL;
		i++;
	}
	free(anim->img);
}

void	free_all_sprites(t_game *game)
{
	free_anim_sprite(&game->anim_player_idle, game);
	free_anim_sprite(&game->anim_player_run, game);
	free_anim_sprite(&game->anim_player_jump, game);
	free_anim_sprite(&game->anim_player_fall, game);
	free_anim_sprite(&game->collectible, game);
	free_anim_sprite(&game->anim_player_hit, game);
	free_anim_sprite(&game->anim_enemy_idle, game);
	free_anim_sprite(&game->anim_enemy_attack, game);
	free_anim_sprite(&game->anim_bubble, game);
	mlx_destroy_image(game->mlx, game->sprite.tl);
	mlx_destroy_image(game->mlx, game->sprite.top);
	mlx_destroy_image(game->mlx, game->sprite.top_right);
	mlx_destroy_image(game->mlx, game->sprite.left);
	mlx_destroy_image(game->mlx, game->sprite.mid);
	mlx_destroy_image(game->mlx, game->sprite.right);
	mlx_destroy_image(game->mlx, game->sprite.bot_left);
	mlx_destroy_image(game->mlx, game->sprite.bot);
	mlx_destroy_image(game->mlx, game->sprite.bot_right);
	mlx_destroy_image(game->mlx, game->sprite.mid_tl);
	mlx_destroy_image(game->mlx, game->sprite.bot_tl);
	mlx_destroy_image(game->mlx, game->sprite.background);
	mlx_destroy_image(game->mlx, game->sprite.background2);
	mlx_destroy_image(game->mlx, game->sprite.water);
	mlx_destroy_image(game->mlx, game->sprite.foreground);
	mlx_destroy_image(game->mlx, game->sprite.door);
	mlx_destroy_image(game->mlx, game->sprite.door_open);
	mlx_destroy_image(game->mlx, game->sprite.bomb);
}
void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(game->map[i]);
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
		free(game->map_copy.map[i]);
		i++;
	}
	free(game->map_copy.map);
}

void	free_list_bubble(t_node_bubble *list)
{
	t_node_bubble	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void	free_list_collectible(t_node *collectible)
{
	t_node	*tmp;

	while (collectible)
	{
		tmp = collectible;
		collectible = collectible->next;
		free(tmp);
	}
}