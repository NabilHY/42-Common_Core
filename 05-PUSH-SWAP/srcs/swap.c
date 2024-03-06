/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:40:16 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/06 13:32:59 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	swap_nodes(t_dlist *tail, t_dlist *penultimate)
{
	int		temp;

	printf("%p\n", tail);
	if (penultimate->prev == NULL)
	{
		temp = penultimate->index;
		penultimate->index = tail->index;
		tail->index = temp;

		penultimate->prev = tail;
		penultimate->next = NULL;
		tail->next = penultimate;
		tail->prev = NULL;

		printf("Tail next %p\n", tail->next);
		printf("Penultimate next%p\n", penultimate->next);
		printf("Tail prev%p\n", tail->prev);
		printf("Penultimate prev%p\n", penultimate->prev);
	}
	else
	{
		temp = penultimate->index;
		penultimate->index = tail->index;
		tail->index = temp;

		penultimate->prev = tail;
		penultimate->next = NULL;
		tail->next = penultimate;
		tail->prev = penultimate->prev;
	}
}

void	swap_stack(t_dlist *tail)
{
	if (!tail)
	{
		ft_putstr_fd("Stack Is empty", 1);
		ft_putchar_fd('\n', 1);
		return ;
	}
	else if (!(tail->next) && !(tail->prev))
	{
		ft_putstr_fd("Only One node Swap cant be done", 1);
		return ;
	}
	else if (tail->prev)
	{
		ft_putstr_fd("start swap\n", 1);
		swap_nodes(tail, tail->prev);
	}
	printf("Entered\n");
}

void	swap_stacks(t_dlist **first_stack, t_dlist **second_stack)
{
	t_dlist	*first_stack_tail;
	t_dlist	*second_stack_tail;

	first_stack_tail = ft_dlstlast(*first_stack);
	second_stack_tail = ft_dlstlast(*second_stack);
	if (!first_stack_tail)
		swap_stack(second_stack_tail);
	else if (!second_stack_tail)
		swap_stack(first_stack_tail);
	else
	{
		swap_stack(first_stack_tail);
		swap_stack(second_stack_tail);
	}
	ft_putstr_fd("ss\n", 1);
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