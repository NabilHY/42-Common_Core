/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:52:06 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/20 01:26:40 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_values(t_dlist *node_1, t_dlist *node_2)
{
	int		temp;

	temp = node_1->value;
	node_1->value = node_2->value;
	node_2->value = temp;
}

void	rotate_nodes(t_dlist *node, t_dlist *next_node)
{
	int			tmp;
	int			second_tmp;
	t_dlist		*current;
	t_dlist		*current_next;

	if (!(next_node->next))
		swap_values(node, next_node);
	else
	{
		current = node;
		current_next = next_node;
		tmp = current->value;
		current->value = ft_dlstlast(node)->value;
		current = current_next;
		current_next = current_next->next;
		while (current)
		{
			second_tmp = current->value;
			current->value = tmp;
			if (!current_next)
				break ;
			tmp = second_tmp;
			current = current_next;
			current_next = current_next->next;
		}
	}
}

void	rotate_stack(t_dlist *stack)
{
	if (!stack)
	{
		ft_putstr_fd("Stack Is empty No Rotate\n", 1);
		ft_putchar_fd('\n', 1);
		return ;
	}
	else if (!(stack->next) && !(stack->prev))
	{
		ft_putstr_fd("Only One node Rotation cant be done\n", 1);
		return ;
	}
	else if (stack->next)
		rotate_nodes(stack, stack->next);
}

void	rotate_stacks(t_dlist **first_stack, t_dlist **second_stack)
{
	if (!first_stack && !second_stack)
		return;
	if (first_stack && !second_stack)
	{
		rotate_stack(ft_dlstfirst(*first_stack));
		ft_putstr_fd("ra\n", 1);
	}
	else if (!first_stack && second_stack)
	{
		rotate_stack(ft_dlstfirst(*second_stack));
		ft_putstr_fd("rb\n", 1);
	}
	else
	{
		rotate_stack(ft_dlstfirst(*first_stack));
		rotate_stack(ft_dlstfirst(*second_stack));
		ft_putstr_fd("rr\n", 1);
	}
}

/*
	Our goal is to shift up the stack with all its elements
		1. Stack is empty or has one node
			simply return
		2. Stack has two nodes
			we'll do a simple swap of the values of the two stack and return
		3. Stack has three or more nodes
			we'll start by changing the head's value to tail's
			to not lose the value we'll save it to the temporary variable
			we'll update the current and its next to move fordward
				we'll enter a loop that will update the whole values of the stack
				including that last one
				at each itteration we'll update the current and current next
				to move one upwards 
				to avoid seg faults we'll break outta of the loop once
				current_next has a null value
				before we overwrite current's value wll save it to a temp
				then we'll give it the heads value (this is only at first itteration)
				then update tmp's value to be the second's for next itteration
				this way we dont lose any values 
				successefully updating the stack
				
		
*/