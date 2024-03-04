/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_enemy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:38:15 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/04 15:03:15 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy_idle_two(t_game *g)
{
	g->enemy_idle.img[14] = load_sprite(g->mlx, "textures/Enemy/Idle/15.xpm");
	g->enemy_idle.img[15] = load_sprite(g->mlx, "textures/Enemy/Idle/16.xpm");
	g->enemy_idle.img[16] = load_sprite(g->mlx, "textures/Enemy/Idle/17.xpm");
	g->enemy_idle.img[17] = load_sprite(g->mlx, "textures/Enemy/Idle/18.xpm");
	g->enemy_idle.img[18] = load_sprite(g->mlx, "textures/Enemy/Idle/19.xpm");
	g->enemy_idle.img[19] = load_sprite(g->mlx, "textures/Enemy/Idle/20.xpm");
	g->enemy_idle.img[20] = load_sprite(g->mlx, "textures/Enemy/Idle/21.xpm");
	g->enemy_idle.img[21] = load_sprite(g->mlx, "textures/Enemy/Idle/22.xpm");
	g->enemy_idle.img[22] = load_sprite(g->mlx, "textures/Enemy/Idle/23.xpm");
	g->enemy_idle.img[23] = load_sprite(g->mlx, "textures/Enemy/Idle/24.xpm");
	g->enemy_idle.img[24] = load_sprite(g->mlx, "textures/Enemy/Idle/25.xpm");
	g->enemy_idle.img[25] = load_sprite(g->mlx, "textures/Enemy/Idle/26.xpm");
	g->enemy_idle.img[26] = load_sprite(g->mlx, "textures/Enemy/Idle/27.xpm");
	g->enemy_idle.img[27] = load_sprite(g->mlx, "textures/Enemy/Idle/28.xpm");
	g->enemy_idle.img[28] = load_sprite(g->mlx, "textures/Enemy/Idle/29.xpm");
	g->enemy_idle.img[29] = load_sprite(g->mlx, "textures/Enemy/Idle/30.xpm");
	g->enemy_idle.img[30] = load_sprite(g->mlx, "textures/Enemy/Idle/31.xpm");
	g->enemy_idle.img[31] = load_sprite(g->mlx, "textures/Enemy/Idle/32.xpm");
}

void	init_enemy_idle(t_game *g)
{
	g->enemy_idle.frame_count = 32;
	g->enemy_idle.img = malloc(sizeof(t_img *) * 32);
	if (!g->enemy_idle.img)
		return ;
	g->enemy_idle.img[0] = load_sprite(g->mlx, "textures/Enemy/Idle/1.xpm");
	g->enemy_idle.img[1] = load_sprite(g->mlx, "textures/Enemy/Idle/2.xpm");
	g->enemy_idle.img[2] = load_sprite(g->mlx, "textures/Enemy/Idle/3.xpm");
	g->enemy_idle.img[3] = load_sprite(g->mlx, "textures/Enemy/Idle/4.xpm");
	g->enemy_idle.img[4] = load_sprite(g->mlx, "textures/Enemy/Idle/5.xpm");
	g->enemy_idle.img[5] = load_sprite(g->mlx, "textures/Enemy/Idle/6.xpm");
	g->enemy_idle.img[6] = load_sprite(g->mlx, "textures/Enemy/Idle/7.xpm");
	g->enemy_idle.img[7] = load_sprite(g->mlx, "textures/Enemy/Idle/8.xpm");
	g->enemy_idle.img[8] = load_sprite(g->mlx, "textures/Enemy/Idle/9.xpm");
	g->enemy_idle.img[9] = load_sprite(g->mlx, "textures/Enemy/Idle/10.xpm");
	g->enemy_idle.img[10] = load_sprite(g->mlx, "textures/Enemy/Idle/11.xpm");
	g->enemy_idle.img[11] = load_sprite(g->mlx, "textures/Enemy/Idle/12.xpm");
	g->enemy_idle.img[12] = load_sprite(g->mlx, "textures/Enemy/Idle/13.xpm");
	g->enemy_idle.img[13] = load_sprite(g->mlx, "textures/Enemy/Idle/14.xpm");
	init_enemy_idle_two(g);
}

void	init_enemy_attack(t_game *g)
{
	g->enemy_attack.frame_count = 7;
	g->enemy_attack.img = malloc(sizeof(t_img *) * 7);
	if (!g->enemy_attack.img)
		return ;
	g->enemy_attack.img[0] = load_sprite(g->mlx, "textures/Enemy/Attack/1.xpm");
	g->enemy_attack.img[1] = load_sprite(g->mlx, "textures/Enemy/Attack/2.xpm");
	g->enemy_attack.img[2] = load_sprite(g->mlx, "textures/Enemy/Attack/3.xpm");
	g->enemy_attack.img[3] = load_sprite(g->mlx, "textures/Enemy/Attack/4.xpm");
	g->enemy_attack.img[4] = load_sprite(g->mlx, "textures/Enemy/Attack/5.xpm");
	g->enemy_attack.img[5] = load_sprite(g->mlx, "textures/Enemy/Attack/6.xpm");
	g->enemy_attack.img[6] = load_sprite(g->mlx, "textures/Enemy/Attack/7.xpm");
}
