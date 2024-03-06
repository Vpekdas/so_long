/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:39:50 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/06 18:01:34 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
void	init_player_idle_two(t_game *g)
{
	g->player_idle.img[11] = load_sprite(g->mlx, "textures/Player/Idle/12.xpm");
	g->player_idle.img[12] = load_sprite(g->mlx, "textures/Player/Idle/13.xpm");
	g->player_idle.img[13] = load_sprite(g->mlx, "textures/Player/Idle/14.xpm");
	g->player_idle.img[14] = load_sprite(g->mlx, "textures/Player/Idle/15.xpm");
	g->player_idle.img[15] = load_sprite(g->mlx, "textures/Player/Idle/16.xpm");
	g->player_idle.img[16] = load_sprite(g->mlx, "textures/Player/Idle/17.xpm");
	g->player_idle.img[17] = load_sprite(g->mlx, "textures/Player/Idle/18.xpm");
	g->player_idle.img[18] = load_sprite(g->mlx, "textures/Player/Idle/19.xpm");
	g->player_idle.img[19] = load_sprite(g->mlx, "textures/Player/Idle/20.xpm");
	g->player_idle.img[20] = load_sprite(g->mlx, "textures/Player/Idle/21.xpm");
	g->player_idle.img[21] = load_sprite(g->mlx, "textures/Player/Idle/22.xpm");
	g->player_idle.img[22] = load_sprite(g->mlx, "textures/Player/Idle/23.xpm");
	g->player_idle.img[23] = load_sprite(g->mlx, "textures/Player/Idle/24.xpm");
	g->player_idle.img[24] = load_sprite(g->mlx, "textures/Player/Idle/25.xpm");
	g->player_idle.img[25] = load_sprite(g->mlx, "textures/Player/Idle/26.xpm");
}

void	init_player_idle(t_game *g)
{
	g->player_idle.frame_count = 26;
	g->player_idle.img = malloc(sizeof(t_img *) * 26);
	if (!g->player_idle.img)
		return ;
	g->player_idle.img[0] = load_sprite(g->mlx, "textures/Player/Idle/1.xpm");
	g->player_idle.img[1] = load_sprite(g->mlx, "textures/Player/Idle/2.xpm");
	g->player_idle.img[2] = load_sprite(g->mlx, "textures/Player/Idle/3.xpm");
	g->player_idle.img[3] = load_sprite(g->mlx, "textures/Player/Idle/4.xpm");
	g->player_idle.img[4] = load_sprite(g->mlx, "textures/Player/Idle/5.xpm");
	g->player_idle.img[5] = load_sprite(g->mlx, "textures/Player/Idle/6.xpm");
	g->player_idle.img[6] = load_sprite(g->mlx, "textures/Player/Idle/7.xpm");
	g->player_idle.img[7] = load_sprite(g->mlx, "textures/Player/Idle/8.xpm");
	g->player_idle.img[8] = load_sprite(g->mlx, "textures/Player/Idle/9.xpm");
	g->player_idle.img[9] = load_sprite(g->mlx, "textures/Player/Idle/10.xpm");
	g->player_idle.img[10] = load_sprite(g->mlx, "textures/Player/Idle/11.xpm");
	init_player_idle_two(g);
}

void	init_player_run(t_game *g)
{
	g->player_run.frame_count = 14;
	g->player_run.img = malloc(sizeof(t_img *) * 14);
	if (!g->player_run.img)
		return ;
	g->player_run.img[0] = load_sprite(g->mlx, "textures/Player/Run/1.xpm");
	g->player_run.img[1] = load_sprite(g->mlx, "textures/Player/Run/2.xpm");
	g->player_run.img[2] = load_sprite(g->mlx, "textures/Player/Run/3.xpm");
	g->player_run.img[3] = load_sprite(g->mlx, "textures/Player/Run/4.xpm");
	g->player_run.img[4] = load_sprite(g->mlx, "textures/Player/Run/5.xpm");
	g->player_run.img[5] = load_sprite(g->mlx, "textures/Player/Run/6.xpm");
	g->player_run.img[6] = load_sprite(g->mlx, "textures/Player/Run/7.xpm");
	g->player_run.img[7] = load_sprite(g->mlx, "textures/Player/Run/8.xpm");
	g->player_run.img[8] = load_sprite(g->mlx, "textures/Player/Run/9.xpm");
	g->player_run.img[9] = load_sprite(g->mlx, "textures/Player/Run/10.xpm");
	g->player_run.img[10] = load_sprite(g->mlx, "textures/Player/Run/11.xpm");
	g->player_run.img[11] = load_sprite(g->mlx, "textures/Player/Run/12.xpm");
	g->player_run.img[12] = load_sprite(g->mlx, "textures/Player/Run/13.xpm");
	g->player_run.img[13] = load_sprite(g->mlx, "textures/Player/Run/14.xpm");
}

void	init_player_jump(t_game *g)
{
	g->player_jump.frame_count = 4;
	g->player_jump.img = malloc(sizeof(t_img *) * 4);
	if (!g->player_jump.img)
		return ;
	g->player_jump.img[0] = load_sprite(g->mlx, "textures/Player/Jump/1.xpm");
	g->player_jump.img[1] = load_sprite(g->mlx, "textures/Player/Jump/2.xpm");
	g->player_jump.img[2] = load_sprite(g->mlx, "textures/Player/Jump/3.xpm");
	g->player_jump.img[3] = load_sprite(g->mlx, "textures/Player/Jump/4.xpm");
}

void	init_player_fall(t_game *g)
{
	g->player_fall.frame_count = 2;
	g->player_fall.img = malloc(sizeof(t_img *) * 2);
	if (!g->player_fall.img)
		return ;
	g->player_fall.img[0] = load_sprite(g->mlx, "textures/Player/Fall/1.xpm");
	g->player_fall.img[1] = load_sprite(g->mlx, "textures/Player/Fall/2.xpm");
}
