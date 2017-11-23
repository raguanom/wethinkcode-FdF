/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:42:51 by raguanom          #+#    #+#             */
/*   Updated: 2017/08/10 12:11:25 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t		ret;

	ret = 1;
	while (n /= 10)
		ret++;
	return (ret);
}

char			*ft_itoa(int nb)
{
	char			*ret;
	size_t			ret_len;
	unsigned int	nb_cpy;

	ret_len = get_len(nb);
	nb_cpy = nb;
	if (nb < 0)
	{
		nb_cpy = -1 * nb;
		ret_len++;
	}
	if (!(ret = ft_strnew(ret_len)))
		return (NULL);
	ret[--ret_len] = nb_cpy % 10 + '0';
	while (nb_cpy /= 10)
		ret[--ret_len] = nb_cpy % 10 + '0';
	if (nb < 0)
		*(ret + 0) = '-';
	return (ret);
}