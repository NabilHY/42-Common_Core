/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:55:16 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/22 05:22:55 by nhayoun          ###   ########.fr       */
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
	return (1);
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

int		min_value(t_dlist **stack)
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
	//stack b === stack a
	stack_node = ft_dlstfirst(*first_stack); // first node in stack b
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
	if (target_node->index < first_size && (target_node->index == node->index))
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
		if (total_cost)
			total_cost++;
		else
		{
			printf("%d\n", get_cost(node));
			printf("%d\n", get_cost(target_node));
			total_cost = get_cost(node) + get_cost(target_node) + 1;
		}
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

int		sort_exception(t_dlist *node, t_dlist *target_node)
{
	int		first_distance;
	int		second_distance;
	int		i;

	i = node->index;
	if (target_node->index < ft_dlstsize(&node) && (target_node->index == node->index))
	{
		while (i-- >= 0)
			rrotate_stacks(&node, &target_node);
		return (1);
	}
	else
	{
		first_distance = ft_dlstsize(&node) - node->index;
		second_distance = ft_dlstsize(&target_node) - target_node->index;
		if ((first_distance) == (second_distance))
		{
			while (i++ < first_distance)
				rotate_stacks(&node, &target_node);
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
	if (index == stack_size - 2)
		swap_stacks(&node, NULL);
	else if (index >= (stack_size / 2))
	while (index++ < stack_size)
		rotate_stacks(&node, NULL);
	else
	{
		while (index-- >= 0)
			rrotate_stacks(&node, NULL);
	}
}

void	get_node_to_b_top(t_dlist *node)
{
	int	value;
	int	stack_size;
	int	index;

	index = node->index;
	value = node->value;
	stack_size = ft_dlstsize(&node);
	if (index == stack_size - 1)
		return ;
	if (index == stack_size - 2)
		swap_stacks(NULL, &node);
	else if (index >= (stack_size / 2))
		while (index++ < stack_size)
			rotate_stacks(NULL ,&node);
	else
	{
		while (index-- >= 0)
			rrotate_stacks(NULL, &node);
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
	get_node_to_a_top(target_node);
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
	get_node_to_b_top(target_node);
	push_to_stack(&node, &target_node, 'A');
}

void sort_init(t_dlist **stack, int flag)
{
	t_dlist *node;
	t_dlist *cheapest_node;

	cheapest_node = find_cheapest(stack);
	ft_putstr_fd("Here",1);
	ft_putnbr_fd(cheapest_node->value, 1);
	if	(flag)
		sort_a_nodes(cheapest_node, cheapest_node->target_node);
	else
		sort_b_nodes(cheapest_node, cheapest_node->target_node);
}

void	clear_data(t_dlist **stack)
{
	t_dlist *node;

	node = ft_dlstfirst(*stack);
	while (node)
	{
		node->target_node = NULL;
		node->cost = 0;
		node = node->next;
	}
}

void	push_last_nodes(t_dlist **stack_b, t_dlist **stack_a)
{
	t_dlist *cheapest;
	t_dlist	*b_node;
	int		size;
	int		i;
	
	b_node = ft_dlstlast(*stack_b);
	cheapest = closest_bnode(b_node, stack_a);
	printf("Cheacpest %d\n", cheapest->value);
	size = ft_dlstsize(stack_a);
	i = cheapest->index;
	if (cheapest->index < (ft_dlstsize(stack_a) / 2))
		while (i >= 0)
		{
			rrotate_stacks(stack_a, NULL);
			i--;
		}
	else
		while (i < size)
		{
			rotate_stacks(stack_a, NULL);
			i++;
		}
	push_to_stack(&b_node, stack_a, 'B');
}

void	push_swap(t_dlist **stack_a, t_dlist **stack_b)
{
		push_to_stack(stack_a, stack_b, 'B');
		push_to_stack(stack_a, stack_b, 'B');
		while (ft_dlstsize(stack_a) > 3)
		{
			set_targets(stack_a, stack_b, 1);
			set_costs(stack_a);
			sort_init(stack_a, 1);
		}
		sort_stack_of_three(stack_a, 'B');
		while (ft_dlstsize(stack_b) > 2)
		{
			set_targets(stack_b, stack_a, 0);
			set_costs(stack_b);
			sort_init(stack_b, 0);
		}
		//push_last_nodes(stack_b, stack_a);
		//push_last_nodes(stack_b, stack_a);
		//sort_stack_of_three(stack_b, 'B');
		//push_to_stack(stack_b, stack_a, 'A');
		printf("sizesize%d\n", ft_dlstsize(stack_b));
		//push_to_stack(stack_b, stack_a, 'A');
		//push_to_stack(stack_b, stack_a, 'A');
	//push_to_stack(stack_b, stack_a, 'A');
	//sort_stack_of_three(stack_a, 'A');
	//ft_dlstprint(*stack_b, 'B');
	//ft_putstr_fd("<===>", 1);
	ft_dlstprint(*stack_b, 'B');
	//printf("%d\n", ft_dlstfirst(*stack_b)->value);
	//push_to_stack(stack_b, stack_a, 'A');
	//push_to_stack(stack_b, stack_a, 'A');
	//push_to_stack(stack_b, stack_a, 'A');
	//push_to_stack(stack_b, stack_a, 'A');
}


/*
	if target node index is less than the size of the node stack
	   if the distance between both of the nodes and the start of the stack
	   is the same then we can reverse rotate until the node index is equal to 0
	else
	   if the distance between both of the nodes and the end of the stack
	   is the same then we can rotate until the the node index is equal to the size

*/