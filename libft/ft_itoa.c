/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:16:32 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/06 15:56:03 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dim(int n)
{
	int	iter;

	iter = 0;
	while ((n /= 10) != 0)
		iter++;
	return (iter + 1);
}

char		*ft_itoa(int n)
{
	char	*p;
	int		flag;
	int		iter;

	iter = ft_dim(n) + 1;
	flag = 1;
	if (n < 0 && iter++)
		flag = -1;
	p = ft_calloc(sizeof(char), iter);
	if (!p)
		return (NULL);
	iter -= 2;
	*(p + iter) = (n % 10) * flag + 48;
	while (iter-- && (n /= 10) != 0)
		*(p + iter) = (n % 10) * flag + 48;
	if (flag == -1)
		*p = '-';
	return (p);
}
