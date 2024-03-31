/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:52:37 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/31 11:17:59 by nhayoun          ###   ########.fr       */
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

int		get_num(char *str)
{
	char valid_ops[][3] = {"pa","pb","ra","rb","rra","rrb","sa","sb", "ss", "rr", "rrr"};
	int	 i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(str, valid_ops[i], ft_strlen(valid_ops[i])))
			return (i);
		i++;
	}
	return (i);
}

int		is_valid(char *str)
{
	char 	valid_ops[][3] = {"pa","pb","ra","rb","rra","rrb","sa","sb", "ss", "rr", "rrr"};
	int	 	i;

	i = 0;
	while (i < 11)
	{
		if (ft_strncmp(str, valid_ops[i], ft_strlen(valid_ops[i])))
			break;
		i++;
	}
	if (i == 11)
		return (0);
	return (1);
};

void	do_op(char *str, t_dlist **stack_a, t_dlist **stack_b)
{
	int	op_num;

	op_num = get_num(str);
	if (op_num == 0)
		move_node_to_stack(stack_b, stack_a);
	else if (op_num == 1)
		move_node_to_stack(stack_a, stack_b);
	else if (op_num == 2)
		rotate_stack(*stack_a);
	else if (op_num == 3)
		rotate_stack(*stack_b);
	else if (op_num == 4)
		rrotate_stack(*stack_a);
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
		rotate_stack(*stack_a);
		rotate_stack(*stack_b);
	}
	else if (op_num == 9)
	{
		rrotate_stack(*stack_a);
		rrotate_stack(*stack_b);
	}
}