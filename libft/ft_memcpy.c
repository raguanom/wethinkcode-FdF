/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 09:59:01 by raguanom          #+#    #+#             */
/*   Updated: 2017/07/28 10:36:54 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*str1;
	const char	*str2;

	if (n == 0 || dst == src)
		return (dst);
	str1 = (char *)dst;
	str2 = (const char *)src;
	i = 0;
	while (i < n && str2[i] != '\0')
	{
		str1[i] = str2[i];
		i++;
	}
	return (dst);
}
