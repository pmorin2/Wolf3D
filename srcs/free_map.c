/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:54:11 by pmorin            #+#    #+#             */
/*   Updated: 2019/01/08 11:41:35 by pmorin           ###   ########.fr       */
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
  while(line[i])
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

int	check_wall(t_data *mlx)
{
  char	*line;

  mlx->col_count = 0;
  while ((mlx->test = get_next_line(mlx->fd, &line)) > 0)
    {
      mlx->col_count++;
      if (mlx->col_count == 1 || mlx->col_count == mlx->line)
	{
	  if (first_last(line))
	    {
	      ft_strdel(&line);
	      error_map(mlx);
	    }
	}
      else
	{
	  if (common_line(line))
	    {
	      ft_strdel(&line);
	      error_map(mlx);
	    }
	}
      ft_strdel(&line);
    }
  return (0);
}

void	free_map(char ***map)
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
