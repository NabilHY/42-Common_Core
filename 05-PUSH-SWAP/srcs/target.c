/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:22:39 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/29 03:23:42 by nhayoun          ###   ########.fr       */
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

void	set_target(t_dlist **first, t_dlist **second, char c)
{
	t_dlist	*node;

	node = ft_dlstfirst(*first);
	if (c == 'A')
	{
		while (node)
		{
			node->target_node = closest_anode(node, second);
			node = node->next;
		}
	}
	else
	{
		while (node)
		{
			node->target_node = closest_bnode(node, second);
			node = node->next;
		}
	}
}