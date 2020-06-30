/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 00:11:15 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/07 17:29:25 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int		sign;
	long	resu;

	resu = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if ((*str == '+' || *str == '-'))
		sign = (*str++) == '-' ? -1 : 1;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		resu = resu * 10 + sign * ((*str++) - '0');
		if ((resu > 0) != (sign > 0))
			return (-(1 + sign) / 2);
	}
	return ((int)resu);
}
