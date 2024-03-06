/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_particles.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:39:11 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/06 16:18:42 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
void	init_bubble(t_game *g)
{
	g->bubble.frame_count = 7;
	g->bubble.img = malloc(sizeof(t_img *) * 7);
	if (!g->bubble.img)
		return ;
	g->bubble.img[0] = load_sprite(g->mlx, "textures/Bubbles/1.xpm");
	g->bubble.img[1] = load_sprite(g->mlx, "textures/Bubbles/2.xpm");
	g->bubble.img[2] = load_sprite(g->mlx, "textures/Bubbles/3.xpm");
	g->bubble.img[3] = load_sprite(g->mlx, "textures/Bubbles/4.xpm");
	g->bubble.img[4] = load_sprite(g->mlx, "textures/Bubbles/5.xpm");
	g->bubble.img[5] = load_sprite(g->mlx, "textures/Bubbles/6.xpm");
	g->bubble.img[6] = load_sprite(g->mlx, "textures/Bubbles/7.xpm");
}

void	init_trail(t_game *g)
{
	g->trail.frame_count = 4;
	g->trail.img = malloc(sizeof(t_img *) * 4);
	if (!g->trail.img)
		return ;
	g->trail.img[0] = load_sprite(g->mlx, "textures/Trail/1.xpm");
	g->trail.img[1] = load_sprite(g->mlx, "textures/Trail/2.xpm");
	g->trail.img[2] = load_sprite(g->mlx, "textures/Trail/3.xpm");
	g->trail.img[3] = load_sprite(g->mlx, "textures/Trail/4.xpm");
}
