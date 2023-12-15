/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:10:44 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/13 14:48:33 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	next_char(unsigned int i, char *ptr)
{
	*ptr += i;
}

int	main(void)
{
	char str[] = "123456";
	ft_striteri(str, next_char);
	printf("%s\n", str);
}*/