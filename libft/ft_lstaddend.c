/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:40:29 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/15 13:33:03 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list *lst, t_list *new)
{
	t_list *lsttemp;
	t_list *cpnew;

	if (lst && new)
	{
		cpnew = ft_lstnew(new->content, new->content_size);
		lsttemp = lst;
		while (lsttemp->next)
			lsttemp = lsttemp->next;
		cpnew->next = NULL;
		lsttemp->next = cpnew;
	}
}
