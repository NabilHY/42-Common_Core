/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstindex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:12:40 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/27 02:26:41 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist		*ft_dlstindex(t_dlist **stack, int index)
{
	t_dlist	*head;
	int		i;

	i = 0;
	if (!stack || !(*stack))
		return (NULL);
	head = ft_dlstfirst(*stack);
	while (i < index && head->next)
	{
		head = head->next;
		i++;
	}
	if (i < index)
		return (NULL);
	return (head);
}