/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:36:46 by vopekdas          #+#    #+#             */
/*   Updated: 2024/02/27 15:33:40 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_anim_bubble(t_game *game, t_anim *anim, int x, int y)
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
t_node_bubble	*create_node_bubble(int x, int y, float velocity_y)
{
	t_node_bubble	*new_node;

	new_node = malloc(sizeof(t_node));
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
	int		i;
	int		rand_x;
	int		rand_y;

	list = NULL;
	i = 0;
	while (i < 50)
	{
		rand_x = rand() % (game->map_width * 3);
		rand_y = rand() % (game->map_height * 3);
		new_node = create_node_bubble(rand_x, rand_y, 0);
		add_node_back_bubble(&list, new_node);
		i++;
	}
	return (list);
}

void	update_anim_bubble(t_game *game)
{
	t_node_bubble	*current;

	current = game->bubble_list;
	while (current)
	{
		current->velocity_y += 0.08;
		if (current->pos_y - current->velocity_y - 5 <= 0)
		{
			current->pos_y = game->map_height + 10;
			current->velocity_y = 0.08;
		}
		draw_anim_bubble(game, &game->anim_bubble, current->pos_x, current->pos_y - current->velocity_y - 5);
		current = current->next;
	}
}