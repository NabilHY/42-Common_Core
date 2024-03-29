/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 04:04:57 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/29 06:41:51 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// fill arr with values from ll
void		fill_arr(t_dlist **stack, int *arr)
{
	int		i;
	int		last_index;
	t_dlist	*node;

	if (!arr || !stack)
		return ;
	i = 0;
	node = *stack;
	last_index = ft_dlstsize(stack);
	while (i < last_index)
	{
		arr[i] = node->value;
		node = node->next;
		i++;
	}
}

void		fill_arr_dif(t_dlist **stack, t_dlist *node, int *arr)
{
	int		i;
	int		last_index;
	t_dlist *target_node;

	if (!arr || !stack || !node)
		return ;
	i = 0;
	target_node = ft_dlstfirst(*stack);
	last_index = ft_dlstsize(stack);
	while (i < last_index && target_node)
	{
		arr[i] = node->value - target_node->value;
		target_node = target_node->next;
		i++;
	}
}

int			max_value(t_dlist **stack)
{
	int stack_arr[ft_dlstsize(stack)];
	int max_index;
	int max;
	int i;

	fill_arr(stack, stack_arr);
	i = 0;
	max = stack_arr[0];
	max_index = 0;
	while (i < ft_dlstsize(stack))
	{
		if (stack_arr[i] > max)
		{
			max = stack_arr[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int			min_value(t_dlist **stack)
{
	int stack_arr[ft_dlstsize(stack)];
	int min_index;
	int min;
	int i;

	fill_arr(stack, stack_arr);
	i = 0;
	min = stack_arr[0];
	min_index = 0;
	while (i < ft_dlstsize(stack))
	{
		if (stack_arr[i] < min)
		{
			min = stack_arr[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int			is_sorted(t_dlist **stack)
{
	t_dlist *head;

	head = ft_dlstfirst(*stack);
	if (!head)
		return (0);
	while (head->next)
	{
		if (head->value < head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
