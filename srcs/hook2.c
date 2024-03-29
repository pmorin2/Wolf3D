/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:04:24 by pmorin            #+#    #+#             */
/*   Updated: 2019/02/06 14:46:35 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"
#include "mlx.h"

int		exit_program(t_data *data)
{
	ft_putendl("Exit Program");
	mlx_destroy_window(data->mlx, data->win);
	free_map(&data->map);
	exit(1);
	return (0);
}

int		key_hook(t_data *data)
{
	key_hook_r_left_right(data);
	key_hook_left_right(data);
	key_hook_stop_hit(data);
	set_image_untextured(data);
	mlx_string_put(data->mlx, data->win, 20, 10, 0xB9121B, "exit = esc");
	mlx_string_put(data->mlx, data->win, 20, 30, 0xB9121B, "help = H");
	if (data->help_menu)
		after_val(data);
	return (0);
}
