/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:27:44 by raguanom          #+#    #+#             */
/*   Updated: 2017/07/20 10:30:29 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ret;
	size_t			i;

	i = 0;
	ret = (unsigned char *)str;
	while (i < n)
	{
		if (ret[i] == (unsigned char)c)
			return (ret + i);
		i++;
	}
	return (NULL);
}
