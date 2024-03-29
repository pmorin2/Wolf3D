/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:04:20 by pmorin            #+#    #+#             */
/*   Updated: 2019/02/06 14:46:15 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

int		key_hook_r_left_right(t_data *data)
{
	if (data->r_right)
	{
		data->t_d = data->dir_x;
		data->dir_x = data->dir_x * cos(-data->rot) - data->dir_y
			* sin(-data->rot);
		data->dir_y = data->t_d * sin(-data->rot) + data->dir_y
			* cos(-data->rot);
		data->t_p = data->plane_x;
		data->plane_x = data->plane_x * cos(-data->rot) - data->plane_y
			* sin(-data->rot);
		data->plane_y = data->t_p * sin(-data->rot) + data->plane_y
			* cos(-data->rot);
	}
	if (data->r_left)
	{
		data->t_d = data->dir_x;
		data->dir_x = data->t_d * cos(data->rot) - data->dir_y * sin(data->rot);
		data->dir_y = data->t_d * sin(data->rot) + data->dir_y * cos(data->rot);
		data->t_p = data->plane_x;
		data->plane_x = data->t_p * cos(data->rot) - data->plane_y
			* sin(data->rot);
		data->plane_y = data->t_p * sin(data->rot) + data->plane_y
			* cos(data->rot);
	}
	return (0);
}

int		key_hook_left_right(t_data *data)
{
	if (data->right)
	{
		if (data->map[(int)data->pos_y][(int)(data->pos_x + data->plane_x
											* data->speed * 5)] != 'x')
			data->pos_x += data->plane_x * data->speed;
		if (data->map[(int)(data->pos_y + data->plane_y
							* data->speed * 5)][(int)data->pos_x] != 'x')
			data->pos_y += data->plane_y * data->speed;
	}
	if (data->left)
	{
		if (data->map[(int)data->pos_y][(int)(data->pos_x - data->plane_x
											* data->speed * 5)] != 'x')
			data->pos_x -= data->plane_x * data->speed;
		if (data->map[(int)(data->pos_y - data->plane_y
							* data->speed * 5)][(int)data->pos_x] != 'x')
			data->pos_y -= data->plane_y * data->speed;
	}
	return (0);
}

int		key_hook_stop_hit(t_data *data)
{
	if (data->up)
	{
		if (data->map[(int)data->pos_y][(int)(data->pos_x + data->dir_x
											* data->speed * 5)] != 'x')
			data->pos_x += data->dir_x * data->speed;
		if (data->map[(int)(data->pos_y + data->dir_y
							* data->speed * 5)][(int)data->pos_x] != 'x')
			data->pos_y += data->dir_y * data->speed;
	}
	if (data->down)
	{
		if (data->map[(int)data->pos_y][(int)(data->pos_x - data->dir_x
											* data->speed * 5)] != 'x')
			data->pos_x -= data->dir_x * data->speed;
		if (data->map[(int)(data->pos_y - data->dir_y
							* data->speed * 5)][(int)data->pos_x] != 'x')
			data->pos_y -= data->dir_y * data->speed;
	}
	return (0);
}

int		key_press(int key, t_data *mlx)
{
	if (key == UP || key == W)
		mlx->up = 1;
	else if (key == DOWN || key == S)
		mlx->down = 1;
	else if (key == 257)
		mlx->speed = 0.05;
	else if (key == RIGHT)
		mlx->right = 1;
	else if (key == LEFT)
		mlx->left = 1;
	else if (key == R_RIGHT)
		mlx->r_right = 1;
	else if (key == R_LEFT)
		mlx->r_left = 1;
	else if (key == ESC)
		err_exit("Exit Program", mlx);
	else if (key == MENU_HIDE)
		mlx->help_menu = (mlx->help_menu + 1) % 2;
	return (0);
}

int		key_release(int key, t_data *mlx)
{
	if (key == UP || key == W)
		mlx->up = 0;
	else if (key == DOWN || key == S)
		mlx->down = 0;
	else if (key == 257)
		mlx->speed = 0.075;
	else if (key == RIGHT)
		mlx->right = 0;
	else if (key == LEFT)
		mlx->left = 0;
	else if (key == R_RIGHT)
		mlx->r_right = 0;
	else if (key == R_LEFT)
		mlx->r_left = 0;
	return (0);
}
