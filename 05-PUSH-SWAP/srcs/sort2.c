/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 04:40:57 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/29 11:44:54 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_smallest(int a, int b)
{
	return (a) ? a < b : b;
}

int			first_itterations(t_dlist **first, t_dlist **second, t_dlist *node, t_dlist *target, int flag)
{
	int		i;
	int		ittr_a;

	i = 0;
	if (flag)
	{
		ittr_a = node->index + 1;
		if (ittr_a == (target->index + 1))
		{
			while (i++ < ittr_a)
				rrotate(first, second);
			return (1);
		}
	}
	else
	{
		ittr_a = ft_dlstsize(first) - node->index - 1;
		if (ittr_a == (ft_dlstsize(second) - target->index - 1))
		{
			while (i++ < ittr_a)
				rotate(first, second);
			return (1);
		}
	}
	return (0);
}

void			second_itterations(t_dlist **first, t_dlist **second, t_dlist *node, t_dlist *target, int flag)
{
	int		i;
	int		ittr_a;
	int		ittr_b;

	i = 0;
	if (flag)
	{
		ittr_a = node->index + 1;
		ittr_b = target->index + 1;
		while (i++ < ft_smallest(ittr_a, ittr_b))
			rrotate(first, second);
	}
	else
	{
		ittr_a = ft_dlstsize(first) - node->index - 1;
		ittr_b = ft_dlstsize(second) - target->index - 1;
		while (i++ < ft_smallest(ittr_a, ittr_b))
			rotate(first, second);
	}
	if (ittr_a > ittr_b)
		node_top(node, first, ft_dlstsize(first), 'A');
	else
		node_top(target, second, ft_dlstsize(second), 'B');
}


int			sorting_exception(t_dlist *node, t_dlist *target, t_dlist **first, t_dlist **second)
{
	int		i;
	int		first_size;
	int		second_size;

	first_size = ft_dlstsize(first);
	second_size = ft_dlstsize(second);
	i = 0;
	if ((node->index < first_size / 2) && (target->index < second_size / 2) && (node->index == target->index))
	{
		if (first_itterations(first, second, node, target, 1))
			return (1);
	}
	else if ((node->index >= first_size / 2) && (target->index >= second_size / 2))
	{
		if (first_itterations(first, second, node, target, 0))
			return (1);
	}
	if ((node->index < first_size / 2) && (target->index < second_size / 2))
	{
		second_itterations(first, second, node, target, 1);
		return (1);
	}
	else if ((node->index >= first_size / 2) && (target->index >= second_size / 2))
	{
		second_itterations(first, second, node, target, 0);
		return (1);
	}
	return (0);
}

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
	if (sorting_exception(cheapest, cheapest->target_node, first_stack, second_stack))
		return ;
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