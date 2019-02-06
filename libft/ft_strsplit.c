/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:43:57 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/13 15:45:37 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_mot(const char *s, char c)
{
	size_t	mot;
	size_t	i;

	mot = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		mot++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (mot);
}

static int		alloc(char **tab, const char *s, char c, size_t *i)
{
	size_t	lettre;
	size_t	j;

	lettre = 0;
	j = 0;
	while (s[i[0]] != c && s[i[0]])
	{
		lettre++;
		i[0]++;
	}
	if (!(tab[i[1]] = ft_strnew(lettre)))
		return (0);
	i[0] -= lettre;
	while (s[i[0]] != c && s[i[0]] != '\0')
	{
		tab[i[1]][j] = s[i[0]];
		i[0]++;
		j++;
	}
	return (1);
}

static char		**ft_rem(char const *s, char c, size_t *i, char **tab)
{
	while (s[i[0]])
	{
		while (s[i[0]] == c)
			i[0]++;
		if (s[i[0]])
		{
			if (!(alloc(tab, s, c, i)))
			{
				free(tab);
				return (NULL);
			}
			i[1]++;
			while (s[i[0]] != c && s[i[0]] != '\0')
				i[0]++;
		}
	}
	tab[i[1]] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i[2];
	char	**tab;

	if (s)
	{
		i[0] = 0;
		i[1] = 0;
		if (!(tab = malloc(sizeof(*tab) * (count_mot(s, c) + 1))))
			return (NULL);
		return (ft_rem(s, c, i, tab));
	}
	return (NULL);
}
