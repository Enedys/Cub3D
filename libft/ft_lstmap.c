/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 00:27:07 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/06 02:03:28 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*element;

	start = NULL;
	while (lst)
	{
		element = ft_lstnew(f(lst->content));
		if (element)
			ft_lstadd_back(&start, element);
		else
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (start);
}
