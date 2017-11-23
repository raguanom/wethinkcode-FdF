/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 13:25:49 by raguanom          #+#    #+#             */
/*   Updated: 2017/11/20 10:25:24 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# include "../libft/libft.h"

# define HEIGHT 1000
# define WIDTH 1500

# define RED 0x00FF5C5C

typedef	struct	s_points
{
	int			row;
	int			col;
	int			z;
	int			color;
}				t_points;

typedef struct	s_map
{
	int			fd;
	t_points	**points;
	int			rows;
	int			cols;
	int			min_z;
	int			max_z;
	void		*mlx;
	void		*win;
	int			deltax;
	int			deltay;
	double		scale;
	double		bend;
}				t_map;

/*
**  Map initialising:
*/
t_map			*init_map(char *file_name);
int				get_num_lines(char *file_name);
int				get_num_points(char *file_name, char **str, char *line);
void			place_lines(t_map *map);
void			get_points(t_map *map);
t_map			*get_points_array(size_t rows, size_t cols, t_map *ret);
int				get_max(t_points **arr, int rows, int cols);
int				get_min(t_points **arr, int rows, int cols);
double			ft_ilerp(double value, double fst, double scnd);
int				ft_lerpi(int fst, int scnd, double percentage);
int				clerp(int color1, int color2, double percentage);

/*
**  Drawing function:
*/
void			place_lines(t_map *map);
void			draw_line(t_map *map, t_points point1, t_points point2);

/*
**  Escape button:
*/
int				hook_esc(int key, t_map *map);
#endif
