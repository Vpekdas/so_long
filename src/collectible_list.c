/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:22:33 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/07 14:19:04 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_node	*create_node_collectible(int x, int y)
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
				new_node = create_node_collectible(x, y);
				add_node_back(&list, new_node);
			}
			x++;
		}
		y++;
	}
	return (list);
}

void	free_list_collectible(t_node *collectible)
{
	t_node	*tmp;

	if (!collectible)
		return ;
	while (collectible)
	{
		tmp = collectible;
		collectible = collectible->next;
		free(tmp);
	}
}
