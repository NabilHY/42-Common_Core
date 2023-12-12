/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:43:58 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/12 08:52:21 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
int    main()
{
    t_list    *link;
    t_list     *node_1;
    t_list     *node_2;
    t_list     *node_3;

    node_1 = ft_lstnew("Node 1");
    node_2 = ft_lstnew("Node 2");
    node_3 = ft_lstnew("Node 3");
    link = NULL;
    ft_lstadd_front(&link, node_1);
    ft_lstadd_front(&link, node_2);
    ft_lstadd_front(&link, node_3);
    printf("%d\n", ft_lstsize(link));
    return (0);
}*/