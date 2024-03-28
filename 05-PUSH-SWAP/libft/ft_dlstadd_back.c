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

void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*tail;

	if (!dlst || !new)
		return ;
	if (!(*dlst))
	{
		*dlst = new;
		return ;
	}
	tail = ft_dlstlast(*dlst);
	new->index = ft_dlstsize(dlst);
	new->prev = tail;
	tail->next = new;
}
