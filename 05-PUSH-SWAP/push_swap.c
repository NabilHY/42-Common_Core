/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:18:39 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/02 19:33:56 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/push_swap.h"
#include "libft/libft.h"
#include "includes/push_swap.h"

int	main(int ac, char **av)
{
	t_dlist	*a_stack_head;
	char	**arr_of_args;
	t_dlist	*current_node;
	
	a_stack_head = NULL;
	arr_of_args = NULL;
	a_stack_head = parse_args(ac, av);
	if (!a_stack_head)
		return (0);
	current_node = a_stack_head;
	while (current_node)
	{
		ft_putstr_fd("node With index :", 1);
		ft_putnbr_fd(current_node->index, 1);
		ft_putstr_fd("\n", 1);
		ft_putstr_fd(" With Value : ", 1);
		ft_putnbr_fd(current_node->value, 1);
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("\n", 1);
		current_node = current_node->next;
	}
	return (0);
}

// find a way to generate a linked list from the givern arguments 
	// make sure that all the inputed arguments are of correct format
		// -> Integer value dont surpass the int max and min
		// -> They dont contain alphabets or symbols
			// the string can have one symbol at its start
				//Otherwise it should throw an error
			// Every char in that number should return 1 when passed to isdigit
// Create a linked list with n of element then pass a value to each item
// Output each item


// Select a number randomly and find a way to push it to the top