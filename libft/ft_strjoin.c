/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:34:29 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/09 13:40:41 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	y;

	if (s1 && s2)
	{
		i = -1;
		y = 0;
		if (!(dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		while (s1[++i])
			dest[y++] = s1[i];
		i = -1;
		while (s2[++i])
			dest[y++] = s2[i];
		return (dest);
	}
	return (NULL);
}
