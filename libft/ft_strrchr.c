/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 09:30:18 by raguanom          #+#    #+#             */
/*   Updated: 2017/08/04 13:54:10 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	if (ft_strchr(str, c) == NULL)
		return (NULL);
	while (*str)
		str++;
	while (*str != c)
		str--;
	return ((char*)str);
}
