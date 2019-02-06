/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:04:16 by pmorin            #+#    #+#             */
/*   Updated: 2019/02/06 14:45:14 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		calc_height_line(t_data *data)
{
	if (data->side == 0)
		data->perp_wall_dis = (data->map_x - data->ray_pos_x
								+ (1 - data->step_x) / 2) / data->ray_dir_x;
	else
		data->perp_wall_dis = (data->map_y - data->ray_pos_y
								+ (1 - data->step_y) / 2) / data->ray_dir_y;
	data->line_height = (int)(HEIGHT / data->perp_wall_dis);
	data->draw_start = -(data->line_height) / 2 + HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = HEIGHT / 2 + data->line_height / 2;
	if (data->draw_start >= HEIGHT)
		data->draw_end = HEIGHT - 1;
}
