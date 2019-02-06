/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:44:02 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/13 15:12:55 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (((unsigned char*)dest) < ((const unsigned char*)src))
		while (++i < n)
			((unsigned char*)dest)[i] = ((const unsigned char*)src)[i];
	else
		while (n--)
			((unsigned char*)dest)[n] = ((const unsigned char*)src)[n];
	return (dest);
}
