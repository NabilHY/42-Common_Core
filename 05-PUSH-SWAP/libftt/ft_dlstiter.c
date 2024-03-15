/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:18:03 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/01 11:41:08 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstiter(t_dlist *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	//while (lst)
	//{
	//	f(lst->content);
	//	lst = lst->next;
	//}
}
