/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:20:35 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/12 18:39:00 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_delimiter(char c, char d)
{
	return (d == c);
}

static size_t	word_count(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!is_delimiter(str[i], c))
		{
			count++;
			while (!is_delimiter(str[i], c) && str[i])
				i++;
		}
		else
			while (is_delimiter(str[i], c) && str[i])
				i++;
	}
	return (count);
}

static char	**wipe_arr(char **ptr, int n)
{
	while (n > 0)
	{
		n--;
		free(ptr[n]);
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**ptrs;
	int		j;
	int		i;
	int		n;

	n = 0;
	i = 0;
	count = word_count(s, c);
	ptrs = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ptrs)
		return (NULL);
	while (s[i] && n < count)
	{
		j = 0;
		while (is_delimiter(s[i], c) && s[i])
			i++;
		while (!is_delimiter(s[i + j], c) && s[i + j])
			j++;
		ptrs[n] = ft_substr(s, i, j);
		if (!ptrs[n])
			return (wipe_arr(ptrs, n));
		i += j;
		n++;
	}
	ptrs[n] = NULL;
	return (ptrs);
}

/*int	main(void)
{
	int i;
	char c;
	char s[] = "@@@@@@@Hel@The@@";
	char **strs;

	c = '@';
	i = 0;
	strs = ft_split(s, c);
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
	return (0);
}*/