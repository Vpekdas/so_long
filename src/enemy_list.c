/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:28:29 by vopekdas          #+#    #+#             */
/*   Updated: 2024/03/16 16:03:01 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_enemy_list	*create_node_enemy(int x, int y)
{
	t_enemy_list	*new_node;

	new_node = malloc(sizeof(t_enemy_list));
	if (!new_node)
		return (NULL);
	new_node->width = 32 * SCALE;
	new_node->height = 80 * SCALE;
	new_node->pos_x = x * SCALE * 32;
	new_node->pos_y = y * SCALE * 32;
	new_node->vx = 0;
	new_node->vy = 0;
	new_node->off_x = SPRITE_SIZE * SCALE;
	new_node->off_y = 0;
	new_node->health = 3;
	new_node->alive = 1;
	new_node->last_frame = 0;
	new_node->invulnerable = 0;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_enemy_back(t_enemy_list **lst, t_enemy_list *new)
{
	t_enemy_list	*current;
	t_enemy_list	*previous;

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

t_enemy_list	*create_list_enemy(t_game *game)
{
	t_enemy_list	*new_node;
	t_enemy_list	*list;
	t_node			*collec;

	list = NULL;
	collec = game->collectible_list;
	while (collec)
	{
		new_node = create_node_enemy((collec->pos_x - 6), collec->pos_y - 1);
		add_node_enemy_back(&list, new_node);
		collec = collec->next;
	}
	return (list);
}

void	free_list_enemy(t_enemy_list *enemy_list)
{
	t_enemy_list	*tmp;

	if (!enemy_list)
		return ;
	while (enemy_list)
	{
		tmp = enemy_list;
		enemy_list = enemy_list->next;
		free(tmp);
	}
}
