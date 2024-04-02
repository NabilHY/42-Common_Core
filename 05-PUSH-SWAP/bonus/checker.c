/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 08:21:29 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/02 02:10:34 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_checker(t_dlist **stack_a, t_dlist **stack_b)
{
	char	line[5];
	
	ft_memset(line, 0, 5);
	while (1)
	{
		read(0, line, 4);
		line[4] = '\0';
		printf("%s", line);
        if (line[0] == '\n' || !is_valid(line))
		{
			if (!line[0])
				break;
            handle_fail(NULL);
			exit(1);
		}
        else
            do_op(line, stack_a, stack_b);
        ft_memset(line, 0, 5);
	}
	if (sorted(stack_a))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_dlist	*a_stack;
	t_dlist	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	a_stack = parse_args(ac, av);
	if (!a_stack)
		return (0);
	if (ft_checker(&a_stack, &b_stack))
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
	return (0);
}