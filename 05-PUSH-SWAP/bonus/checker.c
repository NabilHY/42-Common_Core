/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 08:21:29 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/31 11:51:55 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_checker(t_dlist **stack_a, t_dlist **stack_b)
{
	char	current_line[1024];
	char	*tmp;
	int		ins;
	int		br;
	int 	i;

	(void)stack_a;
	(void)stack_b;
	br = 1;
	ins = 0;
	i = 0;
	while (read(0, current_line, 1024) > 0)
	{
		current_line[3] = '\0';
        tmp = ft_strdup(current_line);
        if (!is_valid(tmp))
		{
            handle_fail(NULL);
			break;
		}
        else
            do_op(tmp, stack_a, stack_b);
        free(tmp);
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