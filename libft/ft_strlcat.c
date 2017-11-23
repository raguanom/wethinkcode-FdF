/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 09:18:03 by raguanom          #+#    #+#             */
/*   Updated: 2017/08/04 13:48:47 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dstlen;

	d = dst;
	s = src;
	n = len;
	while (n-- != 0 && *d != '\0')
		d++;
	dstlen = d - dst;
	n = len - dstlen;
	if (n == 0)
		return (dstlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*(d++) = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dstlen + (s - src));
}
