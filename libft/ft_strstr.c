/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 09:40:00 by raguanom          #+#    #+#             */
/*   Updated: 2017/07/24 11:17:17 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	unsigned int	i;
	unsigned int	j;
	size_t			len;

	len = ft_strlen(little);
	i = 0;
	if (len == 0)
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (little[j] == big[j + i])
		{
			if (j == (len - 1))
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
