/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:43:44 by pmorin            #+#    #+#             */
/*   Updated: 2019/01/23 15:09:24 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	error_def_map(void)
{
	ft_putendl("Map is invalid !");
	exit(1);
}

void	error_map(t_data *mlx)
{
	ft_strdel(&mlx->line_test);
	free_map(&mlx->map);
	ft_putendl("Map is not surrounded by walls !");
	exit(1);
}

void	small_map(void)
{
	ft_putendl("Map is too small !");
	exit(1);
}
