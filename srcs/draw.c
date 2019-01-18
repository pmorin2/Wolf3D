/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheuben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:04:12 by cheuben           #+#    #+#             */
/*   Updated: 2019/01/03 18:04:14 by cheuben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			color_map(t_data *data)
{
	int		color;

	color = 0x000000;
	if (data->side == 0 && data->ray_dir_x > 0)
		color = 0x40A497;
	if (data->side == 0 && data->ray_dir_x < 0)
		color = 0x6F40A4;
	if (data->side == 1 && data->ray_dir_y > 0)
		color = 0xB9121B;
	if (data->side == 1 && data->ray_dir_y < 0)
		color = 0xC4D438;
	return (color);
}

void		print_map(t_data *data, int x)
{
	int		i;
	int		color;

	i = -1;
	color = color_map(data);
	while (++i < WIDTH)
		set_pixel(x, i, 0xCDCDB4, data);
	i = -1;
	while (++i < (data->draw_end - data->draw_start))
		set_pixel(x, i + data->draw_start, color, data);
	i = data->draw_end - 1;
	while (++i < HEIGHT)
	{
		if (i % 2 == 0)
			set_pixel(x, i, 0x808069, data);
		else
			set_pixel(x, i, 0x9C661F, data);
	}
}

void		set_image_untextured(t_data *data)
{
	data->img = mlx_new_image(data->mlx, (int)WIDTH, (int)HEIGHT);
	data->pixel = mlx_get_data_addr(data->img, &data->bpp, &data->size_line,
			&data->endian);
	untextured(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
}
