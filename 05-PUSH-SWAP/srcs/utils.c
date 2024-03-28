/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:21:26 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/28 02:29:20 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_indexes(t_dlist **stack)
{
	t_dlist	*node;
	int	i;

	i = 0;
	node = ft_dlstfirst(*stack);
	while (node)
	{
		node->index = i;
		i++;
		node = node->next;
	}
}