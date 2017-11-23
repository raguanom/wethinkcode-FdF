/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:07:27 by raguanom          #+#    #+#             */
/*   Updated: 2017/07/28 11:10:13 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		*((char*)dst) = *((char*)src);
		dst++;
		src++;
		if (*((char*)dst - 1) == (char)(c))
			return (dst);
		n--;
	}
	return (NULL);
}
