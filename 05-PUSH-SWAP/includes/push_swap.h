/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:19:19 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/05 17:26:36 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
t_dlist	*parse_args(int ac, char **av);
int		check_args(char **arr_of_args);
void	free_arr(char **arr);
int		check_repetition(char **arr_of_args);
void	push_to_stack(t_dlist **first_stack, t_dlist **second_stack, char stack);
void	rotate_stack(t_dlist **stack);
void	rotate_stacks(t_dlist **first_stack, t_dlist **second_stack);
void	rrotate_stack(t_dlist **stack);
void	rrotate_stacks(t_dlist **first_stack, t_dlist **second_stack);
void	swap_stack(t_dlist *stack);
void	swap_stacks(t_dlist **first_stack, t_dlist **second_stack);
#endif