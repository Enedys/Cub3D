/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 01:03:50 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/30 16:36:57 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	refresh_flag(t_identifier *ident, unsigned int flag)
{
	if ((ident->flags & flag) > 0)
		return (-1);
	ident->flags = ident->flags | flag;
	return (1);
}

int	catch_overflow(char *s)
{
	int	i;
	int	len;
	int	res;

	i = 0;
	len = 0;
	while (ft_isspaces(s[i]))
		i++;
	while (s[i] == '0')
		i++;
	while (s[i] && ft_isdigit(s[i]))
	{
		i++;
		len++;
	}
	res = ft_atoi(s);
	if (len > 7)
		return (100000);
	else
		return (res);
}
