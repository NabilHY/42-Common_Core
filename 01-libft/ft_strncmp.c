/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:40:41 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/12 08:48:29 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_cmp(unsigned char c1, unsigned char c2)
{
	return ((unsigned char)c1 - (unsigned char)c2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (char_cmp(s1[i], s2[i]) > 0)
			return (1);
		else if (char_cmp(s1[i], s2[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%d\n" ,ft_strncmp("testss", "test", 7));
	printf("%d\n" ,strncmp("testss", "test", 7));
	return (0);
}
*/