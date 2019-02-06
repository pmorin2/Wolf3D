/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:48:10 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/13 15:04:00 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	size_t	i;
	long	dest;
	int		neg;

	i = 0;
	dest = 0;
	neg = 1;
	while (((nptr[i] > 7 && nptr[i] < 14) || nptr[i] == ' ') && nptr[i])
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		neg = 44 - nptr[i];
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58 && nptr[i])
	{
		dest += nptr[i] - 48;
		if (nptr[i + 1] > 47 && nptr[i + 1] < 58)
			dest *= 10;
		i++;
	}
	return (dest * neg);
}
