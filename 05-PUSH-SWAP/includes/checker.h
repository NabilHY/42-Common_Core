/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 08:23:41 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/31 10:29:54 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H
#endif

#include "./push_swap.h"
#include <stdio.h>
char	*get_next_line(int fd);
void	do_op(char *str, t_dlist **stack_a, t_dlist **stack_b);
int		is_valid(char *str);
int	 	sorted(t_dlist **stack);






