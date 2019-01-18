/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:26:00 by pmorin            #+#    #+#             */
/*   Updated: 2019/01/18 14:39:36 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "wolf3d.h"

static int  def_map(t_data *mlx)
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
	char	*line;

	while ((mlx->test = get_next_line(mlx->fd, &line)) > 0
	       && line[0] == 'x')
	{
		mlx->line++;
		mlx->col_count = -1;
		while (line[++mlx->col_count])
		{
		  if (line[mlx->col_count] != ' ' && line[mlx->col_count] != 'x'
		      && line[mlx->col_count] != 'o')
			{
				ft_strdel(&line);
				return (1);
			}
		}
		ft_strdel(&line);
		if (mlx->col == 0)
			mlx->col = mlx->col_count;
		if (mlx->col != mlx->col_count)
			return (1);
	}
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
	int		i;
	char	*line;

	close_open(mlx);
	if (line_col(mlx))
	  error_def_map();
	if (mlx->line < 4 || mlx->col < 4)
	  small_map();
	def_map(mlx);
	close_open(mlx);
	check_wall(mlx);
	close_open(mlx);
	i = -1;
	while ((mlx->test = get_next_line(mlx->fd, &line)) > 0
	       && line[0] == 'x')
	{
		i++;
		remp_tab(mlx, line, i);
		ft_strdel(&line);
	}
	if (mlx->test == -1)
	  error_map(mlx);
	close(mlx->fd);
	return (0);
}
