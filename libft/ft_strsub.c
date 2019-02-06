/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:13:12 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/09 13:33:37 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (s)
	{
		if (!(dest = ft_strnew(len)))
			return (NULL);
		i = -1;
		while (s[start] && ++i < len)
			dest[i] = s[start++];
		return (dest);
	}
	return (NULL);
}
