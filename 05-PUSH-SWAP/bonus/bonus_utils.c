/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:52:37 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/02 23:36:26 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	sorted(t_dlist **stack)
{
	t_dlist	*head;

	head = ft_dlstfirst(*stack);
	if (!head)
		return (0);
	while (head->next)
	{
		if (head->value < head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int get_num(char *str) {
    if (!ft_strncmp(str, "pa\n", 3))
        return (0);
    else if (!ft_strncmp(str, "pb\n", 3))
        return (1);
    else if (!ft_strncmp(str, "ra\n", 3))
        return (2);
    else if (!ft_strncmp(str, "rb\n", 3))
        return (3);
    else if (!ft_strncmp(str, "rra\n", 4))
        return (4);
    else if (!ft_strncmp(str, "rrb\n", 4))
        return (5);
    else if (!ft_strncmp(str, "sa\n", 3))
        return (6);
    else if (!ft_strncmp(str, "sb\n", 3))
        return (7);
    else if (!ft_strncmp(str, "ss\n", 3))
        return (8);
    else if (!ft_strncmp(str, "rr\n", 3))
        return (9);
    else if (!ft_strncmp(str, "rrr\n", 4))
        return (10);
    else
        return (-1);
}

int is_valid(char *str) {
    if (!ft_strncmp(str, "pa\n", 3) ||
        !ft_strncmp(str, "pb\n", 3) ||
        !ft_strncmp(str, "ra\n", 3) ||
        !ft_strncmp(str, "rb\n", 3) ||
        !ft_strncmp(str, "rra\n", 4) ||
        !ft_strncmp(str, "rrb\n", 4) ||
        !ft_strncmp(str, "sa\n", 3) ||
        !ft_strncmp(str, "sb\n", 3) ||
        !ft_strncmp(str, "ss\n", 3) ||
        !ft_strncmp(str, "rr\n", 3) ||
        !ft_strncmp(str, "rrr\n", 4)) {
        return (1);
    } else {
        return (0);
    }
}

void	do_op(char *str, t_dlist **stack_a, t_dlist **stack_b)
{
	int	op_num;

	op_num = get_num(str);
	if (op_num == 0)
		move_node_to_stack(stack_b, stack_a);
	else if (op_num == 1)
		move_node_to_stack(stack_a, stack_b);
	else if (op_num == 2)
		rotate_stack(ft_dlstlast(*stack_a));
	else if (op_num == 3)
		rotate_stack(ft_dlstlast(*stack_b));
	else if (op_num == 4)
		rrotate_stack(ft_dlstlast(*stack_a));
	else if (op_num == 5)
		rrotate_stack(*stack_b);
	else if (op_num == 6)
		swap_stack(ft_dlstlast(*stack_a));
	else if (op_num == 7)
		swap_stack(ft_dlstlast(*stack_b));
	else if (op_num == 8)
	{
		swap_stack(ft_dlstlast(*stack_a));
		swap_stack(ft_dlstlast(*stack_b));
	}
	else if (op_num == 9)
	{
		rotate_stack(ft_dlstlast(*stack_a));
		rotate_stack(ft_dlstlast(*stack_a));
	}
	else if (op_num == 10)
	{
		rrotate_stack(ft_dlstlast(*stack_a));
		rrotate_stack(ft_dlstlast(*stack_a));
	}
}