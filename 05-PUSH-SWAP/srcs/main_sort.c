/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:55:16 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/18 05:57:35 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			is_sorted(t_dlist **stack)
{
	t_dlist *head;

	head = ft_dlstfirst(*stack);
	while (head)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (0);
}

void		sort_arr(int *arr, int size)
{
	int		temp;
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

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
	while (i < last_index && node)
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
	int 	dif;

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

int		less_exist(int median, t_dlist *tail)
{
	while (tail)
	{
		if (tail->value < median)
			return (1);
		tail = tail->prev;
	}
	return (0);
}

int		max_value(t_dlist **stack)
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

t_dlist		*closest_node(t_dlist *node, t_dlist **stack)
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
			printf("Itteration: %d %d\n", i, diff);
		}
		i++;
	}
	if (!target_node)
		target_node = ft_dlstindex(stack, max_value(stack));
	return (target_node);
}

void		set_targets(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist *stack_a_node;

	stack_a_node = ft_dlstfirst(*stack_a);
	while (stack_a_node)
	{
		stack_a_node->target_node = closest_node(stack_a_node, stack_b);
		stack_a_node = stack_a_node->next;
	}
}

void	push_swap(t_dlist **stack_a, t_dlist **stack_b)
{
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	t_dlist *node;
	//node = closest_node(ft_dlstlast(*stack_a), stack_b);
	set_targets(stack_a, stack_b);
}