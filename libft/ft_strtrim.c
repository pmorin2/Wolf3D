/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:42:59 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/09 14:42:29 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	y;
	size_t	i1;
	size_t	i2;
	size_t	len;
	char	*dest;

	if (s)
	{
		y = -1;
		i1 = 0;
		i2 = ft_strlen(s) - 1;
		while (s[i1] == ' ' || s[i1] == '\n' || s[i1] == '\t')
			i1++;
		while ((s[i2] == ' ' || s[i2] == '\n' || s[i2] == '\t') && i2 > i1)
			i2--;
		len = i2 - i1 + 1;
		if (i2 < i1)
			len = 0;
		if (!(dest = ft_strnew(len)))
			return (NULL);
		while (++y < len)
			dest[y] = s[i1++];
		return (dest);
	}
	return (NULL);
}
