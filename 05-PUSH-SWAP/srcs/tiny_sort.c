/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:56:07 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/29 00:20:38 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_max(t_dlist *head)
{
	int		max;
	t_dlist	*current;

	current = head;
	max = INT_MIN;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

void	sort_nodes(t_dlist *head)
{
	int		max;

	max = find_max(head);
	if (head->value == max)
	{
		if (head->next->value < head->next->next->value)
			swap(&head, NULL);
	}
	else if (head->next->value == max)
	{
		if (head->value > head->next->next->value)
		{
			swap(&head, NULL);
			rotate(&head, NULL);
		}
		else
			rrotate(&head, NULL);
	}
	else
	{
		if (head->next->value < head->value)
			rotate(&head, NULL);
		else
		{
			rotate(&head, NULL);
			swap(&head, NULL);
		}
	}
}

void	tiny_sort(t_dlist **stack)
{
	t_dlist	*head;

	if (!stack || !(*stack) || is_sorted(stack))
		return ;
	head = ft_dlstfirst(*stack);
	if (!(head->next) && !(head->prev))
		return ;
	else if (!(head->next->next))
	{
		if (head->value > head->next->value)
			swap(&head, NULL);
		return ;
	}
	else if (head->next->next->next)
		return ;
	sort_nodes(head);
}