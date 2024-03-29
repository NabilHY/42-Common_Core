/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:28:36 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/29 11:40:14 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/push_swap.h"

void		sort(t_dlist **stack_a, t_dlist **stack_b)
{
	push(stack_a, stack_b, 'B');
	if (ft_dlstsize(stack_a) != 3)
		push(stack_a, stack_b, 'B');
	while (ft_dlstsize(stack_a) > 3)
	{
		set_target(stack_a, stack_b, 'B');
		set_cost(stack_a, stack_b);
		init_a(stack_a, stack_b);
		push(stack_a, stack_b, 'B');
	}
	tiny_sort(stack_a);
	while (ft_dlstsize(stack_b) > 0)
	{
		set_last_target(stack_b, stack_a);
		init_b(stack_b, stack_a);
		push(stack_b, stack_a, 'A');
	}
	get_min_to_top(stack_a);
}