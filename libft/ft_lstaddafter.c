/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddafter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:18:00 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/15 13:36:40 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddafter(t_list *lst, t_list *new)
{
	t_list *cpnew;

	if (lst && new)
	{
		cpnew = ft_lstnew(new->content, new->content_size);
		cpnew->next = lst->next;
		lst->next = cpnew;
	}
}
