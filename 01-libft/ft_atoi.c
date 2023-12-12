/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:10:14 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/10 12:02:58 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/* OVRFLOW CASE NBR HAS REACHED THE LIMIT OF LONG LONG,RETURNS A-1*/
/* UNDERFLOW CASE NBR HAS REACHED THE LIMIT OF LONG LONG,RETURNS A 0*/

static int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

static int	check_overflow(unsigned long nbr, int new_digit, int sign)
{
	if (sign == 1)
	{
		if ((nbr >= 922337203685477580 && new_digit > 7)
			|| (nbr >= 922337203685477581))
			return (-1);
	}
	else if (sign == -1)
	{
		if ((nbr >= 922337203685477580 && new_digit > 8)
			|| (nbr >= 922337203685477581))
			return (0);
	}
	return (1);
}

enum e_vars
{
	sign, 
	overflow,
	
};



int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;
	int				overflow;


	i = 0;
	sign = 1;
	result = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		overflow = check_overflow(result, (str[i] - '0'), sign);
		if (overflow != 1)
			return (overflow);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
/*int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	printf("%d\n", ft_atoi(av[1]));
	printf("%d\n", atoi(av[1]));
}*/
