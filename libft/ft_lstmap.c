/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:16:48 by pmorin            #+#    #+#             */
/*   Updated: 2018/11/13 12:24:58 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lstnew;
	t_list *lstmem;

	if (lst && f)
	{
		if (!(lstnew = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		lstnew = f(lstnew);
		lstmem = lstnew;
		lst = lst->next;
		while (lst)
		{
			if (!(lstnew->next = ft_lstnew(lst->content, lst->content_size)))
				return (NULL);
			lstnew->next = f(lstnew->next);
			lstnew = lstnew->next;
			lst = lst->next;
		}
		return (lstmem);
	}
	return (NULL);
}
