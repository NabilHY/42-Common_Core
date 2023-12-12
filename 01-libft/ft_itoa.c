/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:00:15 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/10 14:08:53 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int	number_digits(int n)
{
	int	digits;

	digits = 0;
	if (n < 0)
	{
		digits++;
		n *= -1;
	}
	while (n > 10)
	{
		n /= 10;
		digits++;
	}
	return (++digits);
}

static void	fill_buf(int n, char *ptr, int index)
{
	if (n < 10)
	{
		ptr[index] = (n % 10) + '0';
		return ;
	}
	else
	{
		ptr[index] = (n % 10) + '0';
		return (fill_buf((n / 10), ptr, --index));
	}
}

char	*ft_itoa(int n)
{
	int		digits_number;
	char	*ptr;

	digits_number = number_digits(n);
	ptr = (char *)malloc(sizeof(char) * (digits_number + 1));
	ptr[digits_number + 1] = '\0';
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	fill_buf(n, ptr, --digits_number);
	return (ptr);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(-1));
	return (0);
}
*/