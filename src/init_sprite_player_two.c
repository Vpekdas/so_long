/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_player_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:03:56 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/10 16:45:47 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

void	init_explotion(t_game *g)
{
	g->explotion.frame_count = 9;
	g->explotion.img = malloc(sizeof(t_img *) * 9);
	if (!g->explotion.img)
		return ;
	g->explotion.img[0] = load_sprite(g->mlx, "textures/Explotion/1.xpm");
	g->explotion.img[1] = load_sprite(g->mlx, "textures/Explotion/2.xpm");
	g->explotion.img[2] = load_sprite(g->mlx, "textures/Explotion/3.xpm");
	g->explotion.img[3] = load_sprite(g->mlx, "textures/Explotion/4.xpm");
	g->explotion.img[4] = load_sprite(g->mlx, "textures/Explotion/5.xpm");
	g->explotion.img[5] = load_sprite(g->mlx, "textures/Explotion/6.xpm");
	g->explotion.img[6] = load_sprite(g->mlx, "textures/Explotion/7.xpm");
	g->explotion.img[7] = load_sprite(g->mlx, "textures/Explotion/8.xpm");
	g->explotion.img[8] = load_sprite(g->mlx, "textures/Explotion/9.xpm");
}
