/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:12:46 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/08 19:32:22 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len)
		{
			len--;
			*(unsigned char *)(len + dst) = *(unsigned char *)(len + src);
		}
	}
	return (dst);
}
/*
int main() {
	char source[] = "This is a test string.";
	//char dest1[50];
	// char dest2[50];


	//memmove(dest1, source, strlen(source) + 1);
	//printf("Standard memmove: %s\n", dest1);

	//ft_memmove(source + 5, source, strlen(source) + 1);
	//printf("ft_memmove: %s\n", source);

	return (0);
}
*/