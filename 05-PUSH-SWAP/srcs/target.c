/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 04:59:02 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/23 05:07:18 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist		*closest_anode(t_dlist *node, t_dlist **stack)
{
	t_dlist *target_node;
	int diff;
	int arr[ft_dlstsize(stack)];
	int i;

	i = 0;
	target_node = NULL;
	fill_arr_dif(stack, node, arr);
	diff = __INT_MAX__;
	while (i < ft_dlstsize(stack))
	{
		if ((arr[i] > 0) && (arr[i] < diff))
		{
			diff = arr[i];
			target_node = ft_dlstindex(stack, i);
		}
		i++;
	}
	if (!target_node)
		target_node = ft_dlstindex(stack, max_value(stack));
	return (target_node);
}

t_dlist		*closest_bnode(t_dlist *node, t_dlist **stack)
{
	t_dlist *target_node;
	int diff;
	int arr[ft_dlstsize(stack)];
	int i;

	i = 0;
	target_node = NULL;
	fill_arr(stack, arr);
	diff = __INT_MAX__;
	while (i < ft_dlstsize(stack))
	{
		if ((arr[i] > node->value) && (arr[i] < diff))
		{
			diff = arr[i];
			target_node = ft_dlstindex(stack, i);
		}
		i++;
	}
	if (!target_node)
		target_node = ft_dlstindex(stack, min_value(stack));
	return (target_node);
}

void		set_targets(t_dlist **first_stack, t_dlist **second_stack, int flag)
{
	t_dlist		*stack_node;

	stack_node = ft_dlstfirst(*first_stack);
	if (flag)
	{
		while (stack_node)
		{
			stack_node->target_node = closest_anode(stack_node, second_stack);
			stack_node = stack_node->next;
		}
	}
	else
	{
		while (stack_node)
		{
			stack_node->target_node = closest_bnode(stack_node, second_stack);
			stack_node = stack_node->next;
		}
	}
}

t_dlist		*find_cheapest(t_dlist **stack)
{
	t_dlist *node;
	t_dlist *cheapest_node;

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

