/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:41:00 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/31 16:55:19 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;



int	ft_color_window(int keycode, t_vars *vars)
{
	static int i = 0;
	static int j = 0;
	if (keycode == XK_Escape)
		mlx_destroy_window(vars->mlx, vars->win);
	if (keycode == 'w')
		j++;
	else if (keycode == 's')
		j--;
	else if (keycode == 'a')
		i--;
	else if (keycode == 'd')
		i++;
	mlx_pixel_put(vars->mlx, vars->win, i, j, 0x00FF0000);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 720, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, ft_color_window, &vars);
	mlx_loop(vars.mlx);
}
