/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheuben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:04:12 by cheuben           #+#    #+#             */
/*   Updated: 2019/01/23 16:24:53 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>

int		pixel_cal(t_data *data, int i, int texnum)
{
  int	color;
  int	d;

  d = i * 256 - HEIGHT * 128 + data->line_height * 128;
  data->texY = (d * 64) / data->line_height / 256;
  color = data->texture[texnum][data->texY][data->texX];
  if (data->side == 1) 
    color = (color >> 1) & 8355711;
  return (color);
}

void		wall_tex(t_data *data)
{
  if (data->side == 0)
    data->wallx = data->pos_y + data->perp_wall_dis * data->ray_dir_y;
  else
    data->wallx = data->pos_x + data->perp_wall_dis * data->ray_dir_x;
  data->wallx -= floor((data->wallx));
  data->texX = (int)(data->wallx * (double)(64));
  /*if (data->side == 0 && data->ray_dir_x > 0)
    data->texX = 64 - data->texX - 1;
  if (data->side == 1 && data->ray_dir_x < 0)
  data->texX = 64 - data->texX - 1;*/
}

int			color_map(t_data *data)
{
  int		texnum;

	texnum = 0;
	if (data->side == 0 && data->ray_dir_x > 0)
		texnum = 0;
	if (data->side == 0 && data->ray_dir_x < 0)
		texnum = 1;
	if (data->side == 1 && data->ray_dir_y > 0)
		texnum = 2;
	if (data->side == 1 && data->ray_dir_y < 0)
		texnum = 3;
	return (texnum);
}

void		print_map(t_data *data, int x)
{
	int		i;
	int		texnum;

	i = -1;
	wall_tex(data);
	texnum = color_map(data);
	while (++i < WIDTH)
		set_pixel(x, i, 0xCDCDB4, data);
	i = -1;
	while (++i < (data->draw_end - data->draw_start))
	  set_pixel(x, i + data->draw_start, pixel_cal(data, i + + data->draw_start, texnum), data);
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
	data->pixel = mlx_get_data_addr(data->img, &data->bpp, &data->size_line
					, &data->endian);
	untextured(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
}
