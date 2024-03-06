/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_player_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:03:56 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/06 16:18:42 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
void	init_player_hit(t_game *g)
{
	g->player_hit.frame_count = 8;
	g->player_hit.img = malloc(sizeof(t_img *) * 8);
	if (!g->player_hit.img)
		return ;
	g->player_hit.img[0] = load_sprite(g->mlx, "textures/Player/Hit/1.xpm");
	g->player_hit.img[1] = load_sprite(g->mlx, "textures/Player/Hit/2.xpm");
	g->player_hit.img[2] = load_sprite(g->mlx, "textures/Player/Hit/3.xpm");
	g->player_hit.img[3] = load_sprite(g->mlx, "textures/Player/Hit/4.xpm");
	g->player_hit.img[4] = load_sprite(g->mlx, "textures/Player/Hit/5.xpm");
	g->player_hit.img[5] = load_sprite(g->mlx, "textures/Player/Hit/6.xpm");
	g->player_hit.img[6] = load_sprite(g->mlx, "textures/Player/Hit/7.xpm");
	g->player_hit.img[7] = load_sprite(g->mlx, "textures/Player/Hit/8.xpm");
}
