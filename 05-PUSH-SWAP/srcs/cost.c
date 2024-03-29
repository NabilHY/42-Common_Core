/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:35:10 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/29 03:55:55 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist		*find_cheapest(t_dlist **stack)
{
	t_dlist *node;
	t_dlist *cheapest_node;

	if (!stack || !(*stack))
		return (NULL);
	node = ft_dlstlast(*stack);
	cheapest_node = node;
	if (cheapest_node->cost == 1)
		return (node);
	else
	{
		while (node)
		{
			if (node->cost < cheapest_node->cost)
				cheapest_node = node;
			node = node->prev;
		}
	}
	return (cheapest_node);
}
int		get_cost(t_dlist *node, int size)
{
	int		cost;

	cost = 0;
	if (node->index >= size / 2)
		cost = size - node->index - 1;
	else if (node->index < size / 2)
		cost = node->index + 1;
	return (cost);
}

void	set_cost(t_dlist **first, t_dlist **second)
{
	t_dlist	*node;
	int		cost;
	int		first_size;
	int		second_size;

	first_size = ft_dlstsize(first);
	second_size = ft_dlstsize(second);
	node = ft_dlstfirst(*first);
	while (node)
	{
		cost = 0;
		cost += get_cost(node, first_size);
		cost += get_cost(node->target_node, second_size);
		node->cost =  cost;
		node = node->next;
	}
}