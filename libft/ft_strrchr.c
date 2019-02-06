/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:25:30 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/13 15:28:15 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*t;
	int		check;

	i = -1;
	check = 0;
	while (s[++i])
		if (s[i] == c)
		{
			t = (char*)s + i;
			check = 1;
		}
	if (s[i] == c)
	{
		t = (char*)s + i;
		check = 1;
	}
	if (check)
		return (t);
	return (NULL);
}
