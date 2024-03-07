/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:18:39 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/07 15:32:30 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "libft/libft.h"
#include "includes/push_swap.h"

int	main(int ac, char **av)
{
	t_dlist	*a_stack;
	t_dlist *b_stack;
	char	**arr_of_args;
	
	a_stack = NULL;
	b_stack = NULL;
	arr_of_args = NULL;
	
	a_stack = parse_args(ac, av);
	if (!a_stack)
		return (0);
	ft_dlstprint(ft_dlstfirst(a_stack));
	sort_stack_of_three(&a_stack);
	ft_dlstprint(ft_dlstfirst(a_stack));
	return (0);
}

/*
Methods
	ft_dlstprint(node)  => print stack
			PUSH METHODS
	push_to_stacks(**stack1, NULL)  => pa
	push_to_stacks(NULL, **stack2)  => pb
			SWAP METHODS
	swap_stacks(**stack1, NULL) => sa
	swap_stacks(NULL, **stack2) => sb
	swap_stacks(**stack1, **stack2) => ss
			ROTATION METHODS
	rotate_stacks(**stack1, NULL)  => ra
	rotate_stacks(NULL, **stack2)  => rb
	rotate_stacks(**stack1, **stack2)  => rr
			REVERSE ROTATION METHODS
	rrotate_stacks(**stack1, NULL)  => rra
	rrotate_stacks(NULL, **stack2)  => rrb
	rrotate_stacks(**stack1, **stack2)  => rrr
*/