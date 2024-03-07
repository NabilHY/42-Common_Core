/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:47:46 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/07 15:30:42 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	compare_and_swap(t_dlist *node, t_dlist *node_next)
{
	int		temp;

	if (node->value > node_next->value)
	{
		temp = node->value;
		node->value  = node_next->value;
		node_next->value = temp;
	}
}

void	sort_nodes(t_dlist *head)
{
	t_dlist	*current;
	t_dlist	*current_next;

	compare_and_swap(head, head->next);
	compare_and_swap(head, head->next->next);
	compare_and_swap(head->next, head->next->next);
}

void	sort_stack_of_three(t_dlist **stack)
{
	t_dlist	*head;

	if (!stack)
		return ;
	if (!(*stack))
	{
		ft_putstr_fd("Stack Empty\n", 1);
		return ;
	}
	head = ft_dlstfirst(*stack);
	if (!(head->next) && !(head->prev))
	{
		ft_putstr_fd("No sorting has been done, stack has one node\n", 1);
		return ;
	}
	else if (!(head->next->next))
	{
		compare_and_swap(head, head->next);
		return ;
	}
	else if (head->next->next->next)
		return ;
	sort_nodes(head);
}

