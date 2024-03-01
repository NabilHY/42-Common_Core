/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:42:29 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/01 15:57:44 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlstfirst(t_dlist *lst)
{
	t_dlist		*head;

	head = lst;
	while (head->prev)
		head = head->prev;
	return (head);
}