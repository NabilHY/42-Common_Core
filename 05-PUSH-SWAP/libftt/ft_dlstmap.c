/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:39:11 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/04 12:49:38 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*head;
	t_dlist	*new_node;
	void	*new_content;
	t_dlist	*current_node;

	current_node = lst;
	if (!current_node)
		return (NULL);
	head = NULL;
	if (!lst || !del || !f)
		return (NULL);
	while (current_node)
	{
		//new_content = f(current_node->content);
		new_node = ft_dlstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_dlstclear(&head, del);
			return (NULL);
		}
		ft_dlstadd_back(&head, new_node);
		current_node = current_node->next;
	}
	return (head);
}
