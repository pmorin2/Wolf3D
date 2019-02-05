/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheuben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:04:40 by cheuben           #+#    #+#             */
/*   Updated: 2019/01/23 16:28:12 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"
#include "mlx.h"

void		err_exit(char *str, t_data *data)
{
	free_map(&data->map);
	mlx_destroy_window(data->mlx, data->win);
	ft_putendl(str);
	exit(1);
}
