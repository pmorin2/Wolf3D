/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:45:24 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/13 15:28:41 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	size_t	i;
	size_t	y;
	size_t	tmp;

	i = -1;
	y = 0;
	if (aiguille[0] == '\0')
		return ((char*)meule_de_foin);
	while (meule_de_foin[++i])
	{
		if (meule_de_foin[i] == aiguille[y])
		{
			tmp = i + 1;
			while (meule_de_foin[tmp] == aiguille[++y] && aiguille[y])
				tmp++;
			if (aiguille[y] == '\0')
				return (((char*)meule_de_foin) + i);
			y = 0;
		}
	}
	return (NULL);
}
