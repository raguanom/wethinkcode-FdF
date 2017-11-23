/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:54:39 by raguanom          #+#    #+#             */
/*   Updated: 2017/11/13 11:40:19 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		swap(int *n1, int *n2)
{
	int			temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

static void		abs_swap(int **c, int **r, t_points *point1, t_points *point2)
{
	if (abs(point1->col - point2->col) >= abs(point1->row - point2->row))
	{
		*c = &point1->col;
		*r = &point1->row;
	}
	else
	{
		swap(&point1->col, &point1->row);
		swap(&point2->col, &point2->row);
		*c = &point1->row;
		*r = &point1->col;
	}
}

static int		alt_color(int height)
{
	return (RED - height * 5000000);
}

void			draw_line(t_map *map, t_points point1, t_points point2)
{
	double		slope;
	double		offset;
	int			iterate;
	int			*c;
	int			*r;

	slope = 0;
	offset = 0;
	abs_swap(&c, &r, &point1, &point2);
	iterate = -1 + (2 * (point1.col < point2.col));
	slope = ((double)abs(point1.row - point2.row) / (double)abs(point1.col -
	point2.col)) * (-1 + (2 * (point1.row < point2.row)));
	while (point1.col != point2.col)
	{
		if (offset >= 0.49999 || offset <= -0.5)
		{
			offset -= -1 + (2 * (point1.row < point2.row));
			point1.row += -1 + (2 * (point1.row < point2.row));
		}
		mlx_pixel_put(map->mlx, map->win, *c, *r,
			alt_color(point2.z - point1.z));
		point1.col += iterate;
		offset += slope;
	}
}

void			place_lines(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols - 1)
		{
			draw_line(map, map->points[i][j + 1], map->points[i][j]);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < map->cols)
	{
		i = 0;
		while (i < map->rows - 1)
		{
			draw_line(map, map->points[i][j], map->points[i + 1][j]);
			i++;
		}
		j++;
	}
}
