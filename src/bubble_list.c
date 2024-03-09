/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:10:54 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/09 16:33:05 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_node_bubble	*create_node_bubble(int x, int y, float velocity_y)
{
	t_node_bubble	*new_node;

	new_node = malloc(sizeof(t_node_bubble));
	if (!new_node)
		return (NULL);
	new_node->pos_x = x;
	new_node->pos_y = y;
	new_node->velocity_y = velocity_y;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_back_bubble(t_node_bubble **lst, t_node_bubble *new)
{
	t_node_bubble	*current;
	t_node_bubble	*previous;

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

t_node_bubble	*create_list_bubble(t_game *game)
{
	t_node_bubble	*new_node;
	t_node_bubble	*list;
	int				i;
	uint32_t		rand_x;
	uint32_t		rand_y;

	list = NULL;
	i = 0;
	game->state = malloc(sizeof(t_xorshift32_state));
	if (!game->state)
		return (NULL);
	game->state->a = UINT_MAX;
	while (i < game->map_width * 5)
	{
		rand_x = xorshift32(game->state) % (game->map_width * 4);
		rand_y = xorshift32(game->state) % (game->map_height * 4);
		new_node = create_node_bubble(rand_x, rand_y, 0);
		add_node_back_bubble(&list, new_node);
		i++;
	}
	free(game->state);
	return (list);
}
