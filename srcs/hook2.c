/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheuben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:04:24 by cheuben           #+#    #+#             */
/*   Updated: 2019/01/23 16:26:41 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
# include "libft.h"
# include "mlx.h"

int		exit_program(void)
{
	ft_putendl("Exit Program");
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
