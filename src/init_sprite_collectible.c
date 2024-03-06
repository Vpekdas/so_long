/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_collectible.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:40:49 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/06 18:01:34 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
void	init_collectible(t_game *g)
{
	g->collectible.frame_count = 14;
	g->collectible.img = malloc(sizeof(t_img *) * 14);
	if (!g->collectible.img)
		return ;
	g->collectible.img[0] = load_sprite(g->mlx, "textures/Collectible/1.xpm");
	g->collectible.img[1] = load_sprite(g->mlx, "textures/Collectible/2.xpm");
	g->collectible.img[2] = load_sprite(g->mlx, "textures/Collectible/3.xpm");
	g->collectible.img[3] = load_sprite(g->mlx, "textures/Collectible/4.xpm");
	g->collectible.img[4] = load_sprite(g->mlx, "textures/Collectible/5.xpm");
	g->collectible.img[5] = load_sprite(g->mlx, "textures/Collectible/6.xpm");
	g->collectible.img[6] = load_sprite(g->mlx, "textures/Collectible/7.xpm");
	g->collectible.img[7] = load_sprite(g->mlx, "textures/Collectible/8.xpm");
	g->collectible.img[8] = load_sprite(g->mlx, "textures/Collectible/9.xpm");
	g->collectible.img[9] = load_sprite(g->mlx, "textures/Collectible/10.xpm");
	g->collectible.img[10] = load_sprite(g->mlx, "textures/Collectible/11.xpm");
	g->collectible.img[11] = load_sprite(g->mlx, "textures/Collectible/12.xpm");
	g->collectible.img[12] = load_sprite(g->mlx, "textures/Collectible/13.xpm");
	g->collectible.img[13] = load_sprite(g->mlx, "textures/Collectible/14.xpm");
}
