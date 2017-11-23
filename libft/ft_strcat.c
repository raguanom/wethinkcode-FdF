/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:00:05 by raguanom          #+#    #+#             */
/*   Updated: 2017/08/04 13:41:28 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int		dstlen;
	int		srclen;
	int		i;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	while (dstlen <= (dstlen + srclen))
	{
		dst[dstlen] = src[i];
		dstlen++;
		srclen--;
		i++;
	}
	return (dst);
}
