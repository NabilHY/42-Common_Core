/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:41:49 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/04 12:47:43 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclear(t_dlist **dlst, void (*del)(void *))
{
	t_dlist	*current_node;
	t_dlist	*next_node;

	if (!dlst || !del)
		return ;
	current_node = *dlst;
	while (current_node)
	{
		next_node = current_node->next;
		ft_dlstdelone(current_node, del);
		current_node = next_node;
	}
	*dlst = NULL;
}
