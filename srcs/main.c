/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheuben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:04:30 by cheuben           #+#    #+#             */
/*   Updated: 2019/01/18 15:44:00 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int player_init(t_data *mlx)
{
	int x;
	int y;

	y = -1;
	while(mlx->map[++y])
	{
		x = -1;
		while(mlx->map[y][++x])
		{
			if (mlx->map[y][x] == 'o')
			{
				mlx->pos_x = (double)x + 0.5;
				mlx->pos_y = (double)y + 0.5;
			}
		}
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
	{
		ft_putendl("Usage : ./wolf3d (map)");
		exit (1);
	}
	data.name_map = av[1];
	init(&data);
	parsor(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Wolf3D");
	player_init(&data);
	set_image_untextured(&data);
	after_val(&data);
	mlx_hook(data.win, 17, 18, exit_program, &data);
	mlx_hook(data.win, 2, (1L << 0), key_press, &data);
	mlx_hook(data.win, 3, (1L << 1), key_release, &data);
	mlx_loop_hook(data.mlx, key_hook, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img);
	return (0);
}
