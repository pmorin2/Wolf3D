/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:04:30 by pmorin            #+#    #+#             */
/*   Updated: 2019/02/06 14:47:21 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"
#include "mlx.h"

static int	player_init(t_data *mlx)
{
	int x;
	int y;
	int	count;

	count = 0;
	y = -1;
	while (mlx->map[++y])
	{
		x = -1;
		while (mlx->map[y][++x])
		{
			if (mlx->map[y][x] == 'o')
			{
				mlx->pos_x = (double)x + 0.5;
				mlx->pos_y = (double)y + 0.5;
				count++;
			}
		}
	}
	if (count != 1)
		error_def_map(mlx);
	return (0);
}

int			main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
	{
		ft_putendl("Usage : ./wolf3d (map)");
		exit(1);
	}
	data.name_map = av[1];
	init(&data);
	parsor(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Wolf3D");
	player_init(&data);
	init_tex(&data);
	set_image_untextured(&data);
	after_val(&data);
	mlx_hook(data.win, 17, 18, exit_program, &data);
	mlx_hook(data.win, 2, (1L << 0), key_press, &data);
	mlx_hook(data.win, 3, (1L << 1), key_release, &data);
	mlx_loop_hook(data.mlx, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
