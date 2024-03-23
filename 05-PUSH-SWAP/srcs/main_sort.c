/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:55:16 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/23 19:28:49 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		push_swap(t_dlist **stack_a, t_dlist **stack_b)
{
		push_to_stack(stack_a, stack_b, 'B');
		push_to_stack(stack_a, stack_b, 'B');

		 while (ft_dlstsize(stack_a) > 3)
		 {
			 set_targets(stack_a, stack_b, 1);
			 set_costs(stack_a);
		 	 sort_init(stack_a, 1);
		 }
		 sort_stack_of_three(stack_a, 'A');
		  while (ft_dlstsize(stack_b) > 2)
		 {
			 set_targets(stack_b, stack_a, 0);
			 set_costs(stack_b);
		 	 sort_init(stack_b, 0);
		 }
}
