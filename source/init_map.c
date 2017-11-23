/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:14:54 by raguanom          #+#    #+#             */
/*   Updated: 2017/11/13 11:10:02 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map			*init_map(char *file_name)
{
	t_map		*ret;
	char		**str;
	char		*line;

	if (!(ret = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	ret->fd = open(file_name, O_RDONLY);
	ret->rows = get_num_lines(file_name);
	ret->cols = get_num_points(file_name, str, line);
	ret->deltax = 50;
	ret->deltay = 500;
	ret->bend = 0.25;
	if (ret->rows >= 90 && ret->cols >= 150)
		ret->scale = 1;
	else if (ret->rows >= 60 && ret->cols >= 100)
		ret->scale = 5;
	else
		ret->scale = 10;
	ret = get_points_array((size_t)ret->rows, (size_t)ret->cols, ret);
	get_points(ret);
	ret->mlx = mlx_init();
	ret->win = mlx_new_window(ret->mlx, WIDTH, HEIGHT, "FDF");
	close(ret->fd);
	return (ret);
}
