/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:50:57 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/01 16:21:33 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	t_dlist	*tail;

	if (!lst)
		return (NULL);
	tail = lst;
	if (!tail->prev)
		return (tail);
	while (tail->)
		tail = tail->next;
	return (tail);
}

