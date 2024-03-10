/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:40:16 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/09 14:58:52 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	swap_indexes(t_dlist *first_node, t_dlist *second_node)
{
	int	temp;

	temp = first_node->index;
	first_node->index = second_node->index;
	second_node->index = temp;
}

void	swap_nodes(t_dlist *tail, t_dlist *penultimate)
{
	swap_indexes(tail, penultimate);
	if (penultimate->prev == NULL)
	{
		penultimate->prev = tail;
		penultimate->next = NULL;
		tail->next = penultimate;
		tail->prev = NULL;

	}
	else
	{
		penultimate->prev->next = tail;
		tail->prev = penultimate->prev;
		tail->next = penultimate;
		penultimate->next = NULL;
		penultimate->prev = tail;
	}
}

void	swap_stack(t_dlist *tail)
{
	if (!tail)
	{
		ft_putstr_fd("Stack Is empty No Swap", 1);
		ft_putchar_fd('\n', 1);
		return ;
	}
	else if (!(tail->next) && !(tail->prev))
	{
		ft_putstr_fd("Only One node Swap cant be done", 1);
		return ;
	}
	else if (tail->prev)
		swap_nodes(tail, tail->prev);
}

void	swap_stacks(t_dlist **first_stack, t_dlist **second_stack)
{
	t_dlist	*first_stack_tail;
	t_dlist	*second_stack_tail;

	if (!first_stack && !second_stack)
		return ;
	if (!first_stack && second_stack)
	{
		second_stack_tail = ft_dlstlast(*second_stack);
		swap_stack(second_stack_tail);
		ft_putstr_fd("sb\n", 1);
	}
	else if (!second_stack && first_stack)
	{
		first_stack_tail = ft_dlstlast(*first_stack);
		swap_stack(first_stack_tail);
		ft_putstr_fd("sa\n", 1);
	}
	else
	{
		second_stack_tail = ft_dlstlast(*second_stack);
		first_stack_tail = ft_dlstlast(*first_stack);
		swap_stack(first_stack_tail);
		swap_stack(second_stack_tail);
		ft_putstr_fd("ss\n", 1);
	}
}


/*
	we'll swap the two top most nodes 0 the swap stack function is gonna take 
	Function swap stack will be taking a PTR to PTR t_dlist (t_dlist tail)
	==> Possible scenarios :
		1. There are no nodes
			if stack head is NULL;
			Do nothing and return;
		2. There is one node
			The passed node next and prev pointers are NULL
			!tail->prev && !tail->next
		3. There are two nodes
			We'll the have to capture the addr of the first one (head)
				it's data would be : head->prev = NULL and head->next = tail
			for the tail (Passed as parameter)
				it's data would be : tail->next = NULL; and tail->prev = head;
			We'll twitch the nodes ptrs to point to each other by chaging their order
			we'll make sure not to manipulate their addresses by mistake
			we'll do it through the following order	
				head->prev=head; tail->next=head; head->next=N; tail->prev=N;
				as for the index we'll simply assign 0  and 1
			
		4. There are three or more nodes
		we managed to get this far so theres are more than three
		we swap the pointers value
		tail->n = penultimate
		tail->p = penultimate->p
		second_tail->n = NULL
		second_tail->p = tail
*/		