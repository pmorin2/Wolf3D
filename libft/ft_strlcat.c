/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:26:14 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/12 12:07:57 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t y;
	size_t len;

	i = -1;
	y = 0;
	len = ft_strlen(src);
	while (dst[++i])
		if (i < size)
			len++;
	while (++i < size && src[y])
	{
		dst[i - 1] = src[y];
		y++;
	}
	dst[i - 1] = '\0';
	return (len);
}
