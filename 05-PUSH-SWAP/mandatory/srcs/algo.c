/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:55:16 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/03 06:01:21 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_dlist **stack_a, t_dlist **stack_b)
{
	int	stack_size;
	int	sorted;

	stack_size = ft_dlstsize(stack_a);
	sorted = is_sorted(stack_a);
	if (stack_size == 2 && !sorted)
		swap(stack_a, NULL);
	else if (stack_size == 3 && !sorted)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !sorted)
		sort(stack_a, stack_b);
}