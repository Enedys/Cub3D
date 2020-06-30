/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:55:29 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/06 23:23:32 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	char	*init;

	if (!s)
		return (NULL);
	init = (char *)s;
	while (s - init < start && *s)
		s++;
	if ((!*s && (s != init + start)))
		return (ft_strdup(""));
	init = (char *)s;
	while ((t_uchar)(init - s) < len && *init)
		init++;
	if (!(p = (char *)malloc(sizeof(char) * (init - s + 1))))
		return (NULL);
	init = p;
	while (len-- && *s)
		*p++ = *s++;
	*p = '\0';
	return (init);
}
