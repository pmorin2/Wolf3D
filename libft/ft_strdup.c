/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:13:33 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/12 11:00:05 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	i = -1;
	if (!(dest = malloc(sizeof(*dest) * (ft_strlen(s) + 1))))
		return (NULL);
	while (++i < ft_strlen(s))
		dest[i] = s[i];
	dest[i] = '\0';
	return (dest);
}
