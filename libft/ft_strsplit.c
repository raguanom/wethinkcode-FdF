/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:01:34 by raguanom          #+#    #+#             */
/*   Updated: 2017/07/28 09:09:00 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int		i;
	int		is_word;

	i = 0;
	is_word = 0;
	while (*str != '\0')
	{
		if (is_word == 0 && *str != c)
		{
			is_word = 1;
			i++;
		}
		else if (is_word == 1 && *str == c)
			is_word = 0;
		str++;
	}
	return (i);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**ret;
	int		a;
	int		b;
	int		d;

	if (!(ret = (char **)malloc(sizeof(char *) * (ft_count_words(str, c) + 1))))
		return (NULL);
	a = -1;
	b = 0;
	while (++a < ft_count_words(str, c))
	{
		d = 0;
		if (!(ret[a] = ft_strnew(ft_count_words(&str[b], c) + 1)))
			ret[a] = NULL;
		while (str[b] == c)
			b++;
		while (str[b] != c && str[b] != '\0')
			ret[a][d++] = str[b++];
		ret[a][d] = '\0';
	}
	ret[a] = 0;
	return (ret);
}
