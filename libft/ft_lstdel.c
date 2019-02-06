/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:09:41 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/12 16:57:38 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *lstnext;

	if (alst && *alst && del)
	{
		while (*alst)
		{
			lstnext = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = lstnext;
		}
	}
}
