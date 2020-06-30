/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:39:21 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/06 01:57:23 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	char	*start;

	p = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(p))
		return (NULL);
	start = p;
	while (*s)
		*p++ = *s++;
	*p = '\0';
	return (start);
}
