/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:23:55 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/13 15:56:42 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *meule_de_foin, const char *aiguille, size_t len)
{
	size_t	i;
	size_t	y;
	size_t	tmp;

	i = -1;
	y = 0;
	if (aiguille[0] == '\0')
		return ((char*)meule_de_foin);
	while (meule_de_foin[++i] && i < len)
	{
		if (meule_de_foin[i] == aiguille[y])
		{
			tmp = i + 1;
			while (meule_de_foin[tmp] == aiguille[++y] && tmp < len
				&& aiguille[y])
				tmp++;
			if (aiguille[y] == '\0')
				return (((char*)meule_de_foin) + i);
			y = 0;
		}
	}
	return (NULL);
}
