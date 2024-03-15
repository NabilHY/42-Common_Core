/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:49:43 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/10 19:47:36 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(int index, int value)
{
	t_dlist	*node;

	node = (t_dlist *)malloc(sizeof(t_dlist));
	if (!node)
		return (NULL);
	node->index = index;
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	node->chunk = 0;
	return (node);
}
