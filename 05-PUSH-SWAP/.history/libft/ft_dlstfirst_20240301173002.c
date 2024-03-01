/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:42:29 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/01 17:30:02 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlstfirst(t_dlist *lst)
{
	t_dlist		*head;

	if (!(*lst) || !lst)
		return (NULL);
	head = lst;
	if (!head->prev)
		return (head);
	while (head->prev)
		head = head->prev;
	return (head);
}
