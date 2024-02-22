/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:19:50 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/22 18:53:05 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collide_with_collectible(t_box player, t_game *game)
{
	int		x;
	int		y;
	t_box	entity_box;

	y = 0;
	while (y < game->map_height - 1)
	{
		x = 0;
		while (x < game->map_width - 1)
		{
			entity_box = map_box_scale(x, y);
			if (game->map[y][x] == 'C' && collide(player, entity_box) == true)
			{
				game->map[y][x] = '0';
				game->collectibles_numbers--;
			}
			x++;
		}
		y++;
	}
}

int	find_collectible_numbers(t_game *game, char **map)
{
	int	x;
	int	y;
	int	collectibles_numbers;

	y = 0;
	collectibles_numbers = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (map[y][x] == 'C')
				collectibles_numbers++;
			x++;
		}
		y++;
	}
	return (collectibles_numbers);
}
void	draw_anim_collectible(t_game *game, t_anim *anim, int x, int y)
{
	int	anim_cooldown;

	anim_cooldown = 100;
	if (getms() - anim->last_frame >= anim_cooldown)
	{
		anim->anim_index++;
		anim->frame++;
		anim->last_frame = getms();
		if (anim->frame >= anim->frame_count)
		{
			anim->anim_index = 0;
			anim->frame = 0;
		}
	}
	draw_sprite(game, anim->img[anim->anim_index], x * 32 * SCALE, y * 32 * SCALE);
}

void	update_anim_collectible(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (map[y][x] == 'C')
				draw_anim_collectible(game, &game->collectible, x, y);
			x++;
		}
		y++;
	}
}

t_node	*create_node(int x, int y)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->pos_x = x;
	new_node->pos_y = y;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_back(t_node **lst, t_node *new)
{
	t_node	*current;
	t_node	*previous;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current)
	{
		previous = current;
		current = current->next;
	}
	previous->next = new;
}
t_node	*create_list_collectible(t_game *game)
{
	int		y;
	int		x;
	t_node	*new_node;
	t_node	*list;

	list = NULL;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
			{
				new_node = create_node(x, y);
				add_node_back(&list, new_node);
			}
			x++;
		}
		y++;
	}
	return (list);
}
