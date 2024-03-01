/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:26:42 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/01 17:48:38 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	t_dlist	*head;
	t_dlist	*next_to_head;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
	
	}
	head = ft_dlstfirst(*lst);
	next_to_head = head->next;
	new->next = next_to_head;
	new->prev = head;
	head->next = new;
	next_to_head->prev = new;
	*lst = new;
}
