/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:47:46 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/23 03:10:59 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_max(t_dlist *head)
{
	int		max;
	t_dlist	*current;

	current = head;
	max = 0;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

void	sort_nodes_a(t_dlist *head)
{
	int		max;

	max = find_max(head);
	if (head->value == max)
	{
		if (head->next->value > head->next->next->value)
			swap_stacks(&head, NULL);
		rrotate_stacks(&head, NULL);
	}
	else if (head->next->value == max)
	{
		if (head->value > head->next->next->value)
			rotate_stacks(&head, NULL);
		else
			swap_stacks(&head, NULL);
	}
	else
	{
		if (head->next->value < head->value)
		{
			rrotate_stacks(&head, NULL);
			swap_stacks(&head, NULL);
		}
	}
}

void	sort_nodes_b(t_dlist *head)
{
	int		max;

	max = find_max(head);
	if (head->value == max)
	{
		if (head->next->value < head->next->next->value)
			swap_stacks(NULL, &head);
	}
	else if (head->next->value == max)
	{
		if (head->value > head->next->next->value)
		{
			swap_stacks(NULL, &head);
			rotate_stacks(NULL, &head);
		}
		else
			rrotate_stacks(NULL, &head);
	}
	else
	{
		if (head->next->value < head->value)
			rotate_stacks(NULL, &head);
		else
		{
			rotate_stacks(NULL, &head);
			swap_stacks(NULL, &head);
		}	
	}
}

void	sort_stack_of_three(t_dlist **stack, char s)
{
	t_dlist	*head;

	if (!stack)
		return ;
	if (!(*stack))
		return ;
	head = ft_dlstfirst(*stack);
	if (!(head->next) && !(head->prev))
	{
		ft_putstr_fd("No sorting has been done, stack has one node\n", 1);
		return ;
	}
	else if (!(head->next->next))
	{
		if (head->value > head->next->value)
			swap_stacks(&head, NULL);
		return ;
	}
	else if (head->next->next->next)
		return ;
	if (s == 'A')
		sort_nodes_a(head);
	else
		sort_nodes_b(head);
}

