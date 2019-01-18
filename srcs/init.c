/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheuben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:04:27 by cheuben           #+#    #+#             */
/*   Updated: 2019/01/18 14:20:34 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init(t_data *data)
{
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->hit = 0;
	data->rot = M_PI / (double)25;
	data->speed = 0.1;
}

void		after_val(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 20, 780, 0x000000, "Menu");
	mlx_string_put(data->mlx, data->win, 20, 820, 0x000000, "Move :");
	mlx_string_put(data->mlx, data->win, 20, 840, 0x000000, "RIGHT = right");
	mlx_string_put(data->mlx, data->win, 20, 860, 0x000000, "LEFT  = left");
	mlx_string_put(data->mlx, data->win, 20, 880, 0x000000, "FRONT = up");
	mlx_string_put(data->mlx, data->win, 20, 900, 0x000000, "BACK  = down");
}
