/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:39:39 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/14 12:12:44 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(unsigned int nbr)
{
	int count;

	count = 1;
	while (nbr > 9)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

static char	*remp_dest(int count, unsigned int *neg, unsigned int nbr
					, char *dest)
{
	neg[1] = nbr;
	if (nbr <= 9)
		neg[1] = nbr + 1;
	while (nbr > 9)
	{
		dest[count - 1] = (nbr % 10) + 48;
		nbr = nbr / 10;
		count--;
	}
	if (neg[1] <= 9 && neg[0])
	{
		dest[count - 1] = '-';
		return (dest);
	}
	dest[count - 1] = nbr + 48;
	if (neg[0])
		dest[count - 2] = '-';
	return (dest);
}

char		*ft_itoa(int n)
{
	int				count;
	unsigned int	neg[2];
	char			*dest;
	unsigned int	nbr;

	neg[0] = 0;
	if (n < 0)
		nbr = -n + neg[0]++;
	else
		nbr = n;
	count = len(nbr);
	if (neg[0] == 1)
		count++;
	if (!(dest = ft_strnew(count)))
		return (NULL);
	return (remp_dest(count, neg, nbr, dest));
}
