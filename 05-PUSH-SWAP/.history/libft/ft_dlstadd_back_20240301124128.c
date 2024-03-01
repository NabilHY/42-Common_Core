/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:33:29 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/01 12:41:29 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_back(t_dlist **head, t_dlist *new)
{
	t_dlist	*last_node;

	if (*(head) == NULL)
	{
		*head = new;
		return ;
	}
	last_node = *head;
	while (last_node)
	{}
}
