/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheuben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:03:58 by cheuben           #+#    #+#             */
/*   Updated: 2019/01/18 15:09:38 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ray_pos(t_data *data, int x)
{
	data->cam_x = 2 * x / (double)WIDTH - 1;
	data->ray_pos_x = data->pos_x;
	data->ray_pos_y = data->pos_y;
	data->ray_dir_x = data->dir_x + data->plane_x * data->cam_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->cam_x;
	data->map_x = (int)data->ray_pos_x;
	data->map_y = (int)data->ray_pos_y;
	data->delta_dis_x = sqrt(1 + (data->ray_dir_y * data->ray_dir_y) /
			(data->ray_dir_x * data->ray_dir_x));
	data->delta_dis_y = sqrt(1 + (data->ray_dir_x * data->ray_dir_x) /
			(data->ray_dir_y * data->ray_dir_y));
}

void		calcul_side_dist(t_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dis_x = (data->ray_pos_x - data->map_x) * data->delta_dis_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dis_x = (data->map_x + 1.0 - data->ray_pos_x) *
			data->delta_dis_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dis_y = (data->ray_pos_y - data->map_y) * data->delta_dis_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dis_y = (data->map_y + 1.0 - data->ray_pos_y) *
			data->delta_dis_y;
	}
}

void		hit(t_data *data)
{
	data->hit = 0;
	while (data->hit == 0)
	{
		if (data->side_dis_x < data->side_dis_y)
		{
			data->side_dis_x += data->delta_dis_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dis_y += data->delta_dis_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map[data->map_y][data->map_x] == 'x')
			data->hit = 1;
	}
}

void		untextured(t_data *data)
{
	int		x;

	x = -1;
	while (++x < WIDTH)
	{
		ray_pos(data, x);
		calcul_side_dist(data);
		hit(data);
		calc_height_line(data);
		print_map(data, x);
	}
}
