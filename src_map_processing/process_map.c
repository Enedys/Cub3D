/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:02:03 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 19:00:28 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int		close_and_return(int fd, int res)
{
	close(fd);
	return (res);
}

int		validate_mapname(char *name)
{
	char	*pos;
	int		fd;

	pos = ft_strrchr(name, '.');
	if (!pos)
		return (-1);
	if (ft_strncmp(pos, ".cub", -1) != 0 || (fd = open(name, O_RDONLY)) < 0)
		return (-1);
	return (close_and_return(fd, 1));
}

int		validate_screenshot(char *name, t_identifier *ident)
{
	if (ft_strncmp(name, "--save", -1) == 0)
	{
		ident->save = 1;
		return (1);
	}
	return (-1);
}

int		process_map(char *filename, t_identifier *ident, char ***map)
{
	int		fd;
	int		res;
	char	*line;
	char	*buffer;

	fd = open(filename, O_RDONLY);
	while (ident->flags < 255 && (res = get_next_line(fd, &line)) > 0)
	{
		buffer = scip_spaces(line);
		res = define_identifier(buffer, ident);
		free(line);
		if (res == -1)
		{
			while ((res = get_next_line(fd, &line)) > 0)
				free(line);
			free(line);
			res = -1;
			break ;
		}
	}
	if (res == -1)
		return (close_and_return(fd, -1));
	if ((*map = get_data(fd)) == NULL)
		return (close_and_return(fd, -1));
	return (close_and_return(fd, 1));
}

char	**get_map(int argc, char **argv, t_identifier *ident)
{
	char	**map;
	int		res;

	if (!ident)
		return (NULL);
	set_identifiers(ident);
	if (argc == 3 && validate_screenshot(argv[2], ident) == -1)
		return (NULL);
	if (argc == 2 || argc == 3)
	{
		if (validate_mapname(argv[1]) == -1)
			return (NULL);
		res = process_map(argv[1], ident, &map);
		if (res < 0)
			return (NULL);
		else if (check_correct(map, ident) > 0)
			return (map);
		else
			return (free_tab(map, -1));
	}
	return (NULL);
}
