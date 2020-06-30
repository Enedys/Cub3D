/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:00:37 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 19:00:14 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	isperson(int c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static int	x_lens(char **map)
{
	int	x;

	x = 0;
	while (map[0][x])
		x++;
	return (x);
}

static int	y_lens(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

static int	check_neighbors(char **map, int i, int j, t_identifier *ident)
{
	int	res;
	int	dim[2];

	res = 1;
	dim[0] = ident->map_x_dim;
	dim[1] = ident->map_y_dim;
	if (j + 1 < dim[0] && !(map[i][j + 1] == '.' || map[i][j + 1] == '1'))
		res *= 0;
	if (j - 1 >= 0 && !(map[i][j - 1] == '.' || map[i][j - 1] == '1'))
		res *= 0;
	if (i - 1 >= 0 && !(map[i - 1][j] == '.' || map[i - 1][j] == '1'))
		res *= 0;
	if (i + 1 < dim[1] && !(map[i + 1][j] == '.' || map[i + 1][j] == '1'))
		res *= 0;
	return (res);
}

int			check_correct(char **map, t_identifier *ident)
{
	int			i;
	int			j;
	int			res;
	static int	pers;

	ident->map_x_dim = x_lens(map);
	ident->map_y_dim = y_lens(map);
	i = 0;
	res = 1;
	while (i < ident->map_y_dim)
	{
		j = 0;
		while (j < ident->map_x_dim)
		{
			if (map[i][j] == 'i')
				res = 0;
			else if (map[i][j] == '.')
				res = check_neighbors(map, i, j, ident);
			pers += isperson(map[i][j++]);
			if (res == 0)
				return (-1);
		}
		i++;
	}
	return (pers == 1 ? 1 : 0);
}
