/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:27:29 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/07 17:00:52 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = 0;
	while (src[len])
		len++;
	while (++i <= len)
		dest[i] = src[i];
	return (dest);
}
