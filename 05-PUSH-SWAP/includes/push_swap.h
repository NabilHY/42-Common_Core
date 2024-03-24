/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:19:19 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/24 03:42:38 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
#include <stdio.h>
t_dlist	*parse_args(int ac, char **av);
int		check_args(char **arr_of_args);
void	free_arr(char **arr);
int		check_repetition(char **arr_of_args);
void	push_to_stack(t_dlist **first_stack, t_dlist **second_stack, char stack);
void	rotate_stack(t_dlist *stack);
void	rotate_stacks(t_dlist **first_stack, t_dlist **second_stack);
void	rrotate_stack(t_dlist *stack);
void	rrotate_stacks(t_dlist **first_stack, t_dlist **second_stack);
void	swap_stacks(t_dlist **first_stack, t_dlist **second_stack);
void	sort_stack_of_three(t_dlist **stack, char s);
void	set_targets(t_dlist **first_stack, t_dlist **second_stack, int flag);
void	set_costs(t_dlist **stack);
void 	sort_init(t_dlist **first_stack, t_dlist **second_stack, int flag);
void	push_swap(t_dlist **stack_a, t_dlist **stack_b);
t_dlist		*find_cheapest(t_dlist **stack);
void		fill_arr(t_dlist **stack, int *arr);
void		fill_arr_dif(t_dlist **stack, t_dlist *node, int *arr);
int			min_value(t_dlist **stack);
int			max_value(t_dlist **stack);
t_dlist		*closest_bnode(t_dlist *node, t_dlist **stack);
void	sort_b_nodes(t_dlist *node, t_dlist *target_node);
#endif