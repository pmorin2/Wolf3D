/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:26:00 by pmorin            #+#    #+#             */
/*   Updated: 2019/02/06 14:24:44 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "wolf3d.h"
#include "libft.h"

static int	def_map(t_data *mlx)
{
	int i;

	if (!(mlx->map = malloc(sizeof(*mlx->map) * (mlx->line + 1))))
	{
		ft_putendl("Malloc error");
		exit(1);
	}
	i = -1;
	while (++i < mlx->line)
		if (!(mlx->map[i] = malloc(sizeof(**mlx->map) * (mlx->col + 1))))
		{
			free_map(&mlx->map);
			ft_putendl("Malloc error");
			exit(1);
		}
	mlx->map[i] = 0;
	return (0);
}

static int	line_col(t_data *mlx)
{
	int check;

	check = 1;
	while ((mlx->test = get_line(mlx->fd, &mlx->l)) >= 0
			&& mlx->l[0] == 'x' && check)
	{
		check = mlx->test;
		mlx->line++;
		if (mlx->line == 1000)
		{
			ft_strdel(&mlx->l);
			ft_putendl("(Map is too big !)");
			return (1);
		}
		mlx->col_count = ft_strlen(mlx->l);
		ft_strdel(&mlx->l);
		if (mlx->col == -1)
			mlx->col = mlx->col_count;
		if (mlx->col != mlx->col_count)
			return (1);
	}
	ft_strdel(&mlx->l);
	if (mlx->line == 0 || mlx->col == 0 || mlx->test == -1)
		return (1);
	return (0);
}

static int	remp_tab(t_data *mlx, char *line, int i)
{
	int k;

	k = -1;
	if ((int)ft_strlen(line) == mlx->col)
	{
		while (line[++k])
			mlx->map[i][k] = line[k];
		mlx->map[i][k] = 0;
	}
	return (0);
}

static int	close_open(t_data *mlx)
{
	if (mlx->fd != -1)
		close(mlx->fd);
	mlx->fd = open(mlx->name_map, O_RDONLY);
	return (0);
}

int			parsor(t_data *mlx)
{
	int check;

	check = 1;
	close_open(mlx);
	if (line_col(mlx))
		error_def_mapfree();
	if (mlx->line < 4 || mlx->col < 4)
		small_map();
	def_map(mlx);
	close_open(mlx);
	check_wall(mlx);
	close_open(mlx);
	while ((mlx->test = get_line(mlx->fd, &mlx->l)) >= 0
			&& mlx->l[0] == 'x' && check)
	{
		check = mlx->test;
		mlx->i++;
		remp_tab(mlx, mlx->l, mlx->i);
		ft_strdel(&mlx->l);
	}
	ft_strdel(&mlx->l);
	if (mlx->test == -1)
		error_map(mlx);
	close(mlx->fd);
	return (0);
}
