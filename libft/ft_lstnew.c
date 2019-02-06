/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:34:04 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/12 15:59:02 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *maillon;

	if (!(maillon = malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(maillon->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memmove(maillon->content, content, content_size);
		maillon->content_size = content_size;
	}
	else
	{
		maillon->content = NULL;
		maillon->content_size = 0;
	}
	maillon->next = NULL;
	return (maillon);
}
