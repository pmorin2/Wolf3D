/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheuben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:04:27 by cheuben           #+#    #+#             */
/*   Updated: 2019/01/23 15:14:47 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init(t_data *data)
{
	data->fd = -1;
	data->col = -1;
	data->line = 0;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->hit = 0;
	data->rot = M_PI / (double)50;
	data->speed = 0.075;
}

void		after_val(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 20, 70, 0xB9121B, "controls :");
	mlx_string_put(data->mlx, data->win, 20, 90, 0xB9121B
				, "View Right = right_arrow");
	mlx_string_put(data->mlx, data->win, 20, 110, 0xB9121B
				, "View Left = left_arrow");
	mlx_string_put(data->mlx, data->win, 20, 130, 0xB9121B
				, "Move Forward = up_arrow");
	mlx_string_put(data->mlx, data->win, 20, 150, 0xB9121B
				, "Move Backward = down_arrow");
	mlx_string_put(data->mlx, data->win, 20, 170, 0xB9121B, "Move Left = A");
	mlx_string_put(data->mlx, data->win, 20, 190, 0xB9121B, "Move Right = D");
}
