/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 05:10:28 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/24 04:09:59 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		sort_exception(t_dlist *node, t_dlist *target_node)
{
	int		first_distance;
	int		size;
	int		second_distance;
	int		i;

	i = node->index;
	size = ft_dlstsize(&node);
	if (target_node->index < size && (target_node->index == node->index))
	{
		while (i >= 0)
		{
			rrotate_stacks(&node, &target_node);
			i--;
		}
		return (1);
	}
	else
	{
		first_distance = ft_dlstsize(&node) - node->index;
		second_distance = ft_dlstsize(&target_node) - target_node->index;
		if ((first_distance) == (second_distance) && node->index != size - 1)
		{
			i = node->index;
			while (i < size)
			{
				rotate_stacks(&node, &target_node);
				i++;
			}
			return (1);
		}
	}
	return (0);
}

void	get_node_to_a_top(t_dlist *node)
{
	int	value;
	int	stack_size;
	int	index;

	index = node->index;
	value = node->value;
	stack_size = ft_dlstsize(&node);
	if (index == stack_size - 1)
		return ;
		
	if (index > (stack_size / 2))
		while (index < stack_size)
		{
			rotate_stacks(&node, NULL);
			index++;
		}
	else
		while (index >= 0)
		{
			rrotate_stacks(&node, NULL);
			index--;
		}
}

void	get_node_to_b_top(t_dlist *node)
{
	int	stack_size;
	int	index;

	index = node->index;
	stack_size = ft_dlstsize(&node);
	if (index == stack_size - 1)
		return ;

	if (index > (stack_size / 2))
		while (index < stack_size)
		{
			rotate_stacks(NULL ,&node);
			index++;
		}
	else
		while (index >= 0)
		{
			rrotate_stacks(NULL, &node);
			index--;
		}
}

void	sort_a_nodes(t_dlist *node, t_dlist *target_node)
{
	int first_size;
	int second_size;
	int	exception;

	exception = sort_exception(node, target_node);
	if (exception)
	{
		push_to_stack(&node, &target_node, 'B');
		return;
	}
	get_node_to_a_top(node);
	get_node_to_b_top(target_node);
	push_to_stack(&node, &target_node, 'B');
}

void	sort_b_nodes(t_dlist *node, t_dlist *target_node)
{
	int first_size;
	int second_size;
	int	exception;

	exception = sort_exception(node, target_node);
	if (exception)
	{
		push_to_stack(&node, &target_node, 'A');
		return;
	}
	get_node_to_b_top(node);
	get_node_to_a_top(target_node);
	push_to_stack(&node, &target_node, 'A');
}

void sort_init(t_dlist **first_stack, t_dlist **second_stack, int flag)
{
	t_dlist *node;
	t_dlist *cheapest_node;

	if	(flag)
	{
		cheapest_node = find_cheapest(first_stack);
		sort_a_nodes(cheapest_node, cheapest_node->target_node);
	}
	else
	{
		cheapest_node = find_cheapest(first_stack);
		sort_b_nodes(cheapest_node, cheapest_node->target_node);
	}
}