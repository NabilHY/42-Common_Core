/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */

/*   Created: 2024/03/01 11:32:49 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/01 12:45:10 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	static int i;
	i++;
	t_dlist	*tail;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tail = ft_dlstlast(*lst);
	printf("%p\n", tail->next);
	printf("%p\n", tail->prev);
	printf("```````````\n")
	//if (i == 2)
	//	exit(0);
	tail->next = new;
	new->prev = tail;
}
