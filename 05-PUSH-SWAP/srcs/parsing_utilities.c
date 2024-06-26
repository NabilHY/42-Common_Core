/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:33:59 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/16 13:45:13 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_repetition(char **arr_of_args)
{
	int		i;
	int		j;
	int		n;
	int		first;
	int		second;

	i = 0;
	while (arr_of_args[i])
	{
		j = i + 1;
		first = ft_atoi(arr_of_args[i]);
		while (arr_of_args[j])
		{
			second = ft_atoi(arr_of_args[j]);
			if (first == second)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_dlist		*parse_args(int ac, char **av)
{
	int		i;
	char 	**args_array;
	int 	args_size;
	t_dlist *a_stack;

	i = 0;
	args_size = 0;
	args_array = NULL;
	a_stack = NULL;
	if (ac != 1)
	{
		i = 0;
		if (ac == 2)
			args_array = ft_split(av[1], 32);
		else
			args_array = &av[1];
		if (!check_args(args_array) || check_repetition(args_array))
		{
			if (ac == 2)
				free_arr(args_array);
			args_array = NULL;
			ft_putstr_fd("Error\n", 1);
			return (NULL);
		}
		while (args_array[args_size])
			args_size++;
		while (args_array[i])
		{
			ft_dlstadd_front(&a_stack, ft_dlstnew(args_size-i-1, ft_atoi(args_array[i])));
			i++;
		}
	}
	return (a_stack);
}
