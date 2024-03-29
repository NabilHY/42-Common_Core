/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 04:40:57 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/29 04:42:22 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		node_top(t_dlist *node, t_dlist **stack, int size, char c)
{
	int	i;
	int ittr;
	t_dlist **first;
	t_dlist **second;

	i = 0;
	first= NULL;
	second = NULL;
	if (c == 'A')
		first = stack;
	else
		second = stack;
	if (node->index >= size / 2)
	{
		ittr = size - node->index - 1;
		while (i++ < ittr)
			rotate(first, second);
	}
	else
	{
		ittr = node->index + 1;
		while (i++ < ittr)
			rrotate(first, second);
	}
}

void		init_a(t_dlist **first_stack, t_dlist **second_stack)
{
	t_dlist 	*cheapest;
	int			first_size;
	int			second_size;

	first_size = ft_dlstsize(first_stack);
	second_size = ft_dlstsize(second_stack);
	cheapest = find_cheapest(first_stack);
	node_top(cheapest, first_stack, first_size, 'A');
	node_top(cheapest->target_node, second_stack, second_size, 'B');
}

void		init_b(t_dlist **first_stack, t_dlist **second_stack)
{
	t_dlist 	*last;
	int			second_size;

	second_size = ft_dlstsize(second_stack);
	last = ft_dlstlast(*first_stack);
	node_top(last->target_node, second_stack, second_size, 'A');
}

void	set_last_target(t_dlist **stack_b, t_dlist **stack_a)
{
	t_dlist		*last;

	last = ft_dlstlast(*stack_b);
	last->target_node = closest_bnode(last, stack_a);
}

void		get_min_to_top(t_dlist **stack_a)
{
	t_dlist	*min_node;
	int		size;
	int		ittr;
	int		i;

	i = 0;
	size = ft_dlstsize(stack_a);
	min_node = ft_dlstindex(stack_a, min_value(stack_a));
	if (min_node->index >= size / 2)
	{
		ittr = size - min_node->index - 1;
		while (i++ < ittr)
			rotate(stack_a, NULL);
	}
	else
	{
		ittr = min_node->index + 1;
		while (i++ < ittr)
			rrotate(stack_a, NULL);
	}
}