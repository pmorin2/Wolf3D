/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:54:11 by pmorin            #+#    #+#             */
/*   Updated: 2019/01/23 15:12:24 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf3d.h"

static int	common_line(char *line)
{
	int i;

	i = 0;
	if (line[i] != 'x')
		return (1);
	while (line[i])
		i++;
	if (line[i - 1] != 'x')
		return (1);
	return (0);
}

static int	first_last(char *line)
{
	int i;

	i = -1;
	while (line[++i])
		if (line[i] != 'x')
			return (1);
	return (0);
}

int			check_wall(t_data *mlx)
{
  int check;

  check = 1;
	mlx->line_count = 0;
	while ((mlx->test = get_line(mlx->fd, &mlx->line_test)) >= 0 && check)
	{
	  check = mlx->test;
		mlx->line_count++;
		if (mlx->line_count == 1 || mlx->line_count == mlx->line)
		{
			if (first_last(mlx->line_test))
				error_map(mlx);
		}
		else
		{
			if (common_line(mlx->line_test))
				error_map(mlx);
		}
		ft_strdel(&mlx->line_test);
	}
	ft_strdel(&mlx->line_test);
	if (mlx->test == -1)
		error_map(mlx);
	return (0);
}

void		free_map(char ***map)
{
	char	**mem;

	if (*map && **map)
	{
		mem = *map;
		while (**map)
		{
			if (*map && **map)
			{
				free(**map);
				**map = NULL;
			}
			(*map)++;
		}
		*map = mem;
		free(*map);
		*map = NULL;
	}
}
