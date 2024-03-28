/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:55:16 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/28 00:57:52 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		push_swap(t_dlist **stack_a, t_dlist **stack_b)
{
	push(stack_a, stack_b, 'B');
	ft_dlstprint(*stack_a, 'A');
	ft_dlstprint(*stack_b, 'B');
	////push(stack_a, stack_b, 'B');
	////push(stack_a, stack_b, 'B');
	////tiny_sort(stack_b);
}
