/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:55:16 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/19 03:51:54 by nhayoun          ###   ########.fr       */
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
	if (index == stack_size - 1)
		return (0);
	else if (index == stack_size - 2)
		return (1);
	else if (index == 0)
		return (1);
	else if (index >= (stack_size / 2))
		while (index++ < stack_size)
			cost++;
	else
		while (index-- >= 0)
			cost++;
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
	if (target_node->index < second_size && (target_node->index == node->index))
		while (i-- >= 0)
			cost++;
	else
	{
		first_distance = first_size - node->index;
		second_distance = second_size - target_node->index;
		if (first_distance == second_distance)
			while (i++ < first_distance)
				cost++;
	}
	return (cost);
}

void	set_costs(t_dlist **stack)
{
	int total_cost;
	t_dlist *node;
	t_dlist *target_node;
	int exceptions;

	node = ft_dlstfirst(*stack);
	target_node = node->target_node;
	while (node)
	{
		total_cost = handle_exceptions(node, target_node);
		if (!total_cost)
			total_cost = get_cost(node) + get_cost(target_node) + 1;
		node->cost = total_cost;
		node = node->next;
		if (node)
			target_node = node->target_node;
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

// void	sort_nodes(t_dlist *node, t_dlist *target_node)
// {
// 	int first_size;
// 	int second_size;

// 	first_size = ft_dlstsize(&node);
// 	second_size = ft_dlstsize(&target_node);

// 	push_to_stack(&node, &target_node, 'A');
// }

// void	sort_init(t_dlist **stack)
// {
// 	t_dlist *node;
// 	t_dlist *cheapest_node;

// 	cheapest_node = find_cheapest(stack);
// 	sort_nodes(cheapest_node, cheapest_node->target_node);
// }

void	push_swap(t_dlist **stack_a, t_dlist **stack_b)
{
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	push_to_stack(stack_a, stack_b, 'B');
	// while (ft_dlstsize(stack_a) > 3)
	// {
		//set_targets(stack_a, stack_b);
		//set_costs(stack_a);
		// 	sort_init(stack_a);
	// }
	//sort_stack_of_three(stack_a, 'A');
}


/*
	if target node index is less than the size of the node stack
	   if the distance between both of the nodes and the start of the stack
	   is the same then we can reverse rotate until the node index is equal to 0
	else
	   if the distance between both of the nodes and the end of the stack
	   is the same then we can rotate until the the node index is equal to the size

*/