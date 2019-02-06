/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:50:10 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/09 12:02:17 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*dest;

	if (s && f)
	{
		i = 0;
		j = 0;
		len = ft_strlen(s);
		if (!(dest = ft_strnew(len)))
			return (NULL);
		while (s[i])
		{
			dest[j] = f(i, s[i]);
			i++;
			j++;
		}
		return (dest);
	}
	return (NULL);
}
