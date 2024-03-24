/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 05:06:44 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/24 05:28:48 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_cost(t_dlist *node)
{
	int cost;
	int stack_size;
	int index;
	int i;

	i = 0;
	cost = 0;
	index = node->index;
	stack_size = ft_dlstsize(&node);

	if (index == 0)
		return (1);
	else if (index == stack_size - 1)
		return (0);
	if (index > (stack_size / 2))
		while (index < stack_size)
		{
			index++;
			cost++;
		}
	else
		while (index >= 0)
		{
			index--;
			cost++;
		}
	return (cost);
}

int		handle_exceptions(t_dlist *node, t_dlist *target_node)
{
	int first_size;
	int first_distance;
	int second_size;
	int second_distance;
	int i;
	int cost;

	first_size = ft_dlstsize(&node);
	second_size = ft_dlstsize(&target_node);
	cost = 0;
	i = node->index;
	if (i == first_size - 1 && target_node->index == second_size - 1)
		return (0);
	if (target_node->index < first_size && (target_node->index == node->index))
		while (i >= 0)
		{
			i--;
			cost++;
		}
	else
	{
		first_distance = first_size - node->index;
		second_distance = second_size - target_node->index;
		if (first_distance == second_distance && node->index != first_distance - 1)
			while (i < first_size)
			{
				i++;
				cost++;
			}
	}
	return (cost);
}

void	set_costs(t_dlist **stack)
{
	int total_cost;
	t_dlist *node;
	t_dlist *target_node;
	int exceptions;

	total_cost = 0;
	node = ft_dlstfirst(*stack);
	while (node)
	{
		if (node)
			target_node = node->target_node;
		total_cost = handle_exceptions(node, target_node);
		if (total_cost)
			total_cost += 1;
		else
		total_cost = get_cost(node) + get_cost(target_node) + 1;
		node->cost = total_cost;
		node = node->next;
	}
}