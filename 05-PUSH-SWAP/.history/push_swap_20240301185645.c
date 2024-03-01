/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:18:39 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/01 18:56:45 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push_swap.h"
#include <stdio.h>

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	check_args(char **arr_of_args)
{
	int	i;
	int	j;

	i = 0;
	while (arr_of_args[i])
	{
		j = 0;
		if (arr_of_args[i][j] == '-' || arr_of_args[i][j] == '+')
			j++;
		while (arr_of_args[i][j])
		{
			if (!ft_isdigit(arr_of_args[i][j]))
			{
				free_arr(arr_of_args);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
#include <stdio.h>
int	main(int ac, char **av)
{
	t_dlist	*a_stack;
	t_dlist	*current_element;
	int		i;
	
	if (ac == 2)
	{
		i = 0;
		av = ft_split(av[1], 32);
		if (!check_args(av))
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
		while (av[i])
		{
			ft_dlstadd_back(&a_stack, ft_dlstnew(i, ft_atoi(av[i])));
			printf("%d\n", a_stack->value);
			i++;
		}
		current_element = ft_dlstfirst(a_stack);
		while (a_stack)
		{
			ft_putstr_fd("Element With index :", 1);
			ft_putnbr_fd(a_stack->index, 1);
			ft_putstr_fd("\n", 1);
			ft_putstr_fd(" With Value : ", 1);
			ft_putnbr_fd(a_stack->value, 1);
			ft_putstr_fd("\n", 1);
			ft_putstr_fd("\n", 1);
			a_stack = a_stack->next;
			sleep(1);
		}
	}
	//else if (ac > 2)
	//{

	//}
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