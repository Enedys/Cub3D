/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:49:35 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/07 16:43:41 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const *p, char const *set)
{
	while (*set && *p != *set)
		set++;
	if (*p == *set)
		return (1);
	return (0);
}

char		*ft_strtrim(char const *start, char const *set)
{
	char	*final;
	char	*p;

	if (!start || !set)
		return (NULL);
	while (*start && in_set(start, set))
		start++;
	final = (char *)start;
	while (*final)
		final++;
	while ((final - start) && in_set(final, set))
		final--;
	p = ft_substr(start, 0, final - start + 1);
	return (p);
}
