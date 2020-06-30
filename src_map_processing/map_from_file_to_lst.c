/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_from_file_to_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 19:04:15 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/30 02:07:26 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	infill_list(t_list *tmp, int fd, int *params)
{
	int		res;
	int		size;
	char	*line;
	size_t	len;

	size = 0;
	len = 0;
	while ((res = get_next_line(fd, &line)) >= 0)
	{
		size++;
		tmp->next = ft_lstnew(ft_strdup(line));
		if (ft_strlen(line) > len)
			len = ft_strlen(line);
		free(line);
		if (!tmp->next)
			return (-1);
		tmp = tmp->next;
		if (res == 0)
			break ;
	}
	params[0] = size + 1 + 2;
	params[1] = len + 2;
	return (1);
}

static char	**read_map(int fd, char *line)
{
	t_list	*start;
	char	**map;
	int		*size;

	start = ft_lstnew(ft_strdup(line));
	free(line);
	if (!start)
		return (NULL);
	size = (int *)malloc(sizeof(int) * 2);
	if (!size || infill_list(start, fd, size) == -1)
	{
		free(size);
		ft_lstclear(&start, free);
		return (NULL);
	}
	map = get_final_map(size, start);
	ft_lstclear(&start, free);
	free(size);
	return (map);
}

char		**get_data(int fd)
{
	int		res;
	char	*line;
	char	**map;

	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (*line != '\0')
			break ;
		free(line);
	}
	if (res == -1)
		return (NULL);
	map = read_map(fd, line);
	return (map);
}
