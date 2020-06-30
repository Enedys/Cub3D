/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:24:27 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/07 00:31:43 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_lstsize(t_list *lst)
{
	int iter;

	iter = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		iter++;
		lst = lst->next;
	}
	return (iter);
}
