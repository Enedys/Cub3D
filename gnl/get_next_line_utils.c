/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 22:40:20 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/24 20:38:33 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_g(const char *s)
{
	const char	*str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}

char	*ft_strjoin_g(char const *s1, char const *s2)
{
	size_t	len;
	char	*p;
	char	*start;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen_g(s2) + ft_strlen_g(s1);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	start = p;
	while (len-- && *s1)
		*p++ = *s1++;
	len++;
	while (len-- && *s2)
		*p++ = *s2++;
	*p = '\0';
	return (start);
}

char	*ft_strchr_g(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return ((char *)NULL);
}

char	*ft_strdup_g(const char *s)
{
	char	*p;
	char	*start;

	p = (char *)malloc(sizeof(char) * (ft_strlen_g(s) + 1));
	if (!(p))
		return (NULL);
	start = p;
	while (*s)
		*p++ = *s++;
	*p = '\0';
	return (start);
}

t_lists	*ft_lstnew_g(void *content, int fd)
{
	t_lists	*element;

	element = (t_lists *)malloc(sizeof(t_lists));
	if (!element)
	{
		free(content);
		return (NULL);
	}
	element->content = content;
	element->fd = fd;
	element->next = NULL;
	return (element);
}
