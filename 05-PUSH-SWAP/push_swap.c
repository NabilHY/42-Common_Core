/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:18:39 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/05 02:38:07 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "libft/libft.h"
#include "includes/push_swap.h"

int	main(int ac, char **av)
{
	t_dlist	*a_stack_head;
	t_dlist *b_stack_head;
	char	**arr_of_args;
	t_dlist	*current_node;
	
	a_stack_head = NULL;
	b_stack_head = NULL;
	arr_of_args = NULL;
	
	a_stack_head = parse_args(ac, av);
	if (!a_stack_head)
		return (0);
	current_node = a_stack_head;
	while (current_node)
	{
		ft_putstr_fd("Stack 1 : " ,1);
		ft_putnbr_fd(current_node->index, 1);
		ft_putstr_fd("<===>", 1);
		ft_putnbr_fd(current_node->value, 1);
		ft_putstr_fd("\n", 1);
		current_node = current_node->next;
	}
	//current_node = ft_dlstfirst(a_stack_head);
	//ft_putstr_fd("\nStack 1\n", 1);
	//push_to_stack(&a_stack_head, &b_stack_head, 'A');
	//push_to_stack(&a_stack_head, &b_stack_head, 'A');
	//push_to_stack(&a_stack_head, &b_stack_head, 'A');
	//push_to_stack(&a_stack_head, &b_stack_head, 'A');
	//push_to_stack(&b_stack_head, &a_stack_head, 'B');
	//push_to_stack(&b_stack_head, &a_stack_head, 'B');
	//current_node = ft_dlstfirst(a_stack_head);
	// WARNING ++>>>> CURRENT_NODE COULD RETURN NULL, DONT LOOP UNLESS YOU SURE TRUTHY
	//if (current_node)
	//{
	//	while (current_node)
	//	{
	//		ft_putstr_fd("Stack 1 : " ,1);
	//		ft_putnbr_fd(current_node->index, 1);
	//		ft_putstr_fd("<===>", 1);
	//		ft_putnbr_fd(current_node->value, 1);
	//		ft_putstr_fd("\n", 1);
	//		current_node = current_node->next;
	//	}
	//}
	//ft_putstr_fd("\nStack 2\n", 1);
	//current_node = ft_dlstfirst(b_stack_head);
	//while (current_node)
	//{
	//	ft_putstr_fd("Stack 2 : " ,1);
	//	ft_putnbr_fd(current_node->index, 1);
	//	ft_putstr_fd("<===>", 1);
	//	ft_putnbr_fd(current_node->value, 1);
	//	ft_putstr_fd("\n", 1);
	//	current_node = current_node->next;
	//}
	
	return (0);
}