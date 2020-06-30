/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:30:11 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/06 01:57:06 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (!(n / 10 == 0))
			ft_putnbr_fd(-(n / 10), fd);
		ft_putchar_fd(48 - n % 10, fd);
	}
	else
	{
		if (n / 10 == 0)
			ft_putchar_fd(48 + n % 10, fd);
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(48 + n % 10, fd);
		}
	}
}
