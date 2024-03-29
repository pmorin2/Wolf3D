/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:04:36 by pmorin            #+#    #+#             */
/*   Updated: 2019/02/06 14:47:33 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_pixel(int x, int y, int color, t_data *data)
{
	int	index;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		index = (y * data->size_line) + (x * data->bpp / 8);
		data->pixel[index] = (color & 0xFF);
		data->pixel[index + 1] = (color & 0xFF00) >> 8;
		data->pixel[index + 2] = (color & 0xFF0000) >> 16;
	}
}
