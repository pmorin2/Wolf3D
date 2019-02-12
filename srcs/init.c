/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:04:27 by pmorin            #+#    #+#             */
/*   Updated: 2019/02/12 16:47:12 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"
#include <math.h>
#include "libft.h"

void	init_tex(t_data *data)
{
	int i;
	int j;
	int xorcolor;
	int xycolor;

	j = -1;
	while (++j < 64)
	{
		i = -1;
		while (++i < 64)
		{
			xorcolor = (j * 256 / 64) ^ (i * 256 / 64);
			xycolor = i * 128 / 64 + j * 128 / 64;
			data->texture[0][j][i] = (8421504) * (j % 8 && i % 8
												&& j != 63 && i != 63);
			data->texture[1][j][i] = 12582912 * (j % 16 && i % 16
												&& j != 63 && i != 63);
			data->texture[2][j][i] = 256 * xycolor + 65536 * xycolor;
			data->texture[3][j][i] = 256 * xorcolor;
		}
	}
}

void	init(t_data *data)
{
	data->fd = -1;
	data->col = -1;
	data->line = 0;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->hit = 0;
	data->i = -1;
	data->l = NULL;
	data->rot = M_PI / (double)50;
	data->speed = 0.075;
}

void	after_val(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 20, 70, 0xB9121B, "controls :");
	mlx_string_put(data->mlx, data->win, 20, 90, 0xB9121B
				, "View Right = right_arrow");
	mlx_string_put(data->mlx, data->win, 20, 110, 0xB9121B
				, "View Left = left_arrow");
	mlx_string_put(data->mlx, data->win, 20, 130, 0xB9121B
				, "Move Forward = W");
	mlx_string_put(data->mlx, data->win, 20, 150, 0xB9121B
				, "Move Backward = S");
	mlx_string_put(data->mlx, data->win, 20, 170, 0xB9121B, "Move Left = A");
	mlx_string_put(data->mlx, data->win, 20, 190, 0xB9121B, "Move Right = D");
}
