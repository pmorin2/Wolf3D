/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:43:44 by pmorin            #+#    #+#             */
/*   Updated: 2019/01/21 15:45:26 by pmorin           ###   ########.fr       */
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
	free_map(&mlx->map);
	ft_putendl("Map is not surrounded by walls !");
	exit(1);
}

void	small_map(void)
{
	ft_putendl("Map is too small !");
	exit(1);
}
