/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:55:16 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/13 13:50:41 by nhayoun          ###   ########.fr       */
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

void		fill_arr(t_dlist *stack, int *arr)
{
	int		i;
	int		last_index;
	t_dlist	*node;

	if (!arr || !stack)
		return ;
	i = 0;
	node = stack;
	last_index = ft_dlstsize(&stack);
	while (i < last_index && node)
	{
		arr[i] = node->value;
		node = node->next;
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

//void		fill_arr_with_chunk(t_dlist *stack, int *arr)
//{
//	t_dlist	*current_node;
//	int		i;
	
//	i = 0;
//	current_node = ft_dlstlast(stack);
//	if (current_node->chunk == 1)
//	{
//		arr[i] = current_node->value;
//		i++;
//		current_node = current_node->prev;
//	}
//	while (current_node && !(current_node->chunk))
//	{
//		arr[i] = current_node->value;
//		current_node = current_node->prev;
//		i++;
//	}
//}
//int			get_chunk_size(t_dlist **stack)
//{
//	t_dlist *tail_node;
//	int		i;

//	i = 0;
//	tail_node = ft_dlstlast(*stack);
//	if (tail_node->chunk == 1)
//	{
//		tail_node = tail_node->prev;
//		i++;
//	}
//	while (!(tail_node->prev))
//	{
//		tail_node = tail_node->prev;
//		i++;
//	}
//	return (i);
//}

//t_dlist		*get_chunk_node(t_dlist **stack)
//{
//	t_dlist *tail_node;

//	tail_node = ft_dlstlast(*stack);
//	if (tail_node->chunk == 1)
//		tail_node = tail_node->prev;
//	while (!(tail_node->prev))
//		tail_node = tail_node->prev;
//		return (tail_node);
//}

//void		push_chunk(t_dlist **stack, int	median_value, int chunk_size)
//{
//	t_dlist	*tail;
//	int		i;

//	i = 0;
//	while (i < chunk_size)
//	{
		
//		i++;
//	}
//}

//void		resolve_b_chunks(t_dlist **stack_a, t_dlist **stack_b)
//{
//	int		chunk_size;
//	t_dlist	*tail_node;
//	int		median_value;
//	int		stack_arr[get_chunk_size(stack_b)];
	
//	tail_node = ft_dlstlast(stack_a);
//	if (tail_node->chunk == 1 && tail_node->next->chunk == 1)
//	{
//		push_to_stack(stack_b, stack_a, 'B');
//		return ;
//	}
//	fill_arr_with_chunk(*stack_a ,stack_arr);
//	median_value = stack_arr[get_chunk_size(stack_a) / 2];
	
//}

void		ft_chunck_a(t_dlist **stack_a, t_dlist **stack_b)
{
	int		stack[ft_dlstsize(stack_a)];
	int		bottom_value;
	int		median_value;
	int		last_index;
	int		i;

	i = 0;
	fill_arr(*stack_a, stack);
	last_index = ft_dlstsize(stack_a);
	sort_arr(stack, last_index);
	median_value = stack[(last_index / 2)];
	bottom_value = ft_dlstfirst(*stack_a)->value;
	while (ft_dlstsize(stack_a) > 0 && less_exist(median_value, ft_dlstlast(*stack_a)))
	{
		if (median_value > ft_dlstlast(*stack_a)->value)
			push_to_stack(stack_a, stack_b, 'B');
		else {
			if (ft_dlstlast(*stack_a)->index > ft_dlstsize(stack_a) / 2)
				rotate_stacks(stack_a, NULL);
			else
				rrotate_stack(*stack_a);
		}
	}
}

void	push_swap(t_dlist **stack_a, t_dlist **stack_b)
{
	while (ft_dlstsize(stack_a) > 3)
	{
		//\ft_chunck_a(stack_a, stack_b);
		//sort_stack_of_three(stack_a, 'A');
		//ft_dlstlast(*stack_b)->chunk = 1;
	}
	
}