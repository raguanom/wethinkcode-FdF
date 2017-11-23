/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:53:01 by raguanom          #+#    #+#             */
/*   Updated: 2017/11/23 09:50:03 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		main_loop(char **av, t_map *map, int *i, int *j)
{
	map = init_map(av[1]);
	*i = -1;
	while (++(*i) < map->rows)
	{
		*j = -1;
		while (++(*j) < map->cols - 1)
			draw_line(map, map->points[*i][*j + 1], map->points[*i][*j]);
	}
	*j = -1;
	while (++(*j) < map->cols)
	{
		*i = -1;
		while (++(*i) < map->rows - 1)
			draw_line(map, map->points[*i][*j], map->points[*i + 1][*j]);
	}
	mlx_key_hook(map->win, hook_esc, 0);
	mlx_loop(map->mlx);
}

static int		check_fd(char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (-1 == fd)
	{
		ft_putstr("Check permissions for [");
		ft_putstr(file_name);
		ft_putstr("] Can only read file with ");
		ft_putendl("correct permmision.");
		exit(-1);
		return (1);
	}
	close(fd);
	return (0);
}

static void		die_usage(char *chr)
{
	ft_putstr("Usage: {");
	ft_putstr(chr);
	ft_putstr("} ");
	ft_putendl("--[file_name].fdf--");
	exit(-1);
}

static void		die_file_overflow(void)
{
	ft_putstr("Too many input files. ");
	ft_putstr("Please provide valid --[.fdf]-- file.\n");
	exit(-1);
}

int		main(int ac, char **av)
{
	t_map	*map;
	int		i;
	int		j;

	if (ac == 2)
	{
		if (ft_strrchr(av[1], '.') == NULL)
			die_usage(av[0]);
		if (ft_strcmp(".fdf", ft_strrchr(av[1], '.')) != 0)
			die_usage(av[0]);
		else if (check_fd(av[1]))
			exit(-1);
		else
			main_loop(av, map, &i, &j);
	}
	else
	{
		if (ac > 2)
			die_file_overflow();
		else
			die_usage(av[0]);
	}
	return (0);
}
