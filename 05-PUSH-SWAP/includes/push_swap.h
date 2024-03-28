/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:19:19 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/28 02:25:23 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
#include <stdio.h>
# include <limits.h>
t_dlist	*parse_args(int ac, char **av);
int		check_args(char **arr_of_args);
void	free_arr(char **arr);
int		check_repetition(char **arr_of_args);
void	push(t_dlist **first_stack, t_dlist **second_stack, char stack);
void	rotate(t_dlist **first_stack, t_dlist **second_stack);
void	rrotate(t_dlist **first_stack, t_dlist **second_stack);
void	swap(t_dlist **first_stack, t_dlist **second_stack);
void	update_indexes(t_dlist **stack);
void	tiny_sort(t_dlist **stack);
void	push_swap(t_dlist **stack_a, t_dlist **stack_b);
void	fill_arr(t_dlist **stack, int *arr);
void	fill_arr_dif(t_dlist **stack, t_dlist *node, int *arr);
int		min_value(t_dlist **stack);
int		max_value(t_dlist **stack);
void	tiny_sort(t_dlist **stack);

#endif