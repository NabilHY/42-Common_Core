/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:26:42 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/01 15:40:08 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	t_dlist	*head;
	t_dlist	*

	if (!lst || !new)
		return ;
	head = *lst;
	while (head)
		head = head->prev;
	new->next = *lst;
	*lst = new;
}
