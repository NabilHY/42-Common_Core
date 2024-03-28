/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:33:59 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/28 09:23:45 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		args_num(int ac, char **av)
{
	int j;
	int n;
	char **temp;
	int args_size;

	j = 1;
	args_size = 0;
	while (j < ac)
	{
		{
			temp = ft_split(av[j], ' ');
			n = 0;
			while (temp[n])
			{
				args_size++;
				n++;
			}
			free_arr(temp);
		}
		j++;
	}
	return (args_size);
}

char	**ft_sets(int ac, char **av)
{
	int i;
	int j;
	int n;
	char **temp;
	char **args_arr;

	i = 0;
	j = 1;
	args_arr = malloc(sizeof(char *) * (args_num(ac, av) + 1));
	if (!args_arr)
		return (NULL);
	while (j < ac)
	{
		temp = ft_split(av[j], ' ');
		n = 0;
		while (temp[n])
			args_arr[i++] = ft_strdup(temp[n++]);
		free_arr(temp);
		temp = NULL;
		j++;
	}
	args_arr[i] = NULL;
	return (args_arr);
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
		if (!ft_isdigit(arr_of_args[i][j]))
			return (0);
		while (arr_of_args[i][j])
		{
			if (!ft_isdigit(arr_of_args[i][j]))
				return (0);
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
	args_size = args_num(ac, av);
	a_stack = NULL;
	if (ac != 1)
	{
		i = 0;
		if (ac == 2)
			args_array = ft_split(av[1], 32);
		else
			args_array = ft_sets(ac, av);
		if (!check_args(args_array) || check_repetition(args_array))
			return (handle_fail(args_array));
		while (args_array[i])
		{
			ft_dlstadd_front(&a_stack, ft_dlstnew(args_size - i, ft_atoi(args_array[i])));
			i++;
		}
		free_arr(args_array);
	}
	return (a_stack);
}
