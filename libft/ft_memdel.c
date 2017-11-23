/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:48:35 by raguanom          #+#    #+#             */
/*   Updated: 2017/07/26 14:33:11 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	unsigned char **str;

	if (ap != NULL)
	{
		str = (unsigned char **)ap;
		free((void *)*str);
		*ap = NULL;
	}
}
