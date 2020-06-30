/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:22:33 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 18:58:50 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	is_obstacle(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '2')
		return (1);
	else
		return (0);
}

void		y_span(t_linker *link, float dir)
{
	int		ds;

	ds = link->ident->pos->y_pos - (link->ident->pos->y_pos / MAP_SCALE)
															* MAP_SCALE;
	if (((link->ident->pos->speed * cos(PI / 180 * (link->ident->pos->dir
	+ dir * 180.)) >= ds) && is_obstacle(link->map, link->ident->pos->x_pos /
			MAP_SCALE, (link->ident->pos->y_pos / MAP_SCALE) - 1) == 1) ||
(link->ident->pos->speed * cos(PI / 180 * (link->ident->pos->dir + dir * 180.))
	<= (ds = ds - MAP_SCALE) && is_obstacle(link->map, link->ident->pos->x_pos /
				MAP_SCALE, (link->ident->pos->y_pos / MAP_SCALE) + 1) == 1))
	{
		if (ds > MAP_SCALE / 5)
			link->ident->pos->y_pos -= ds - MAP_SCALE / 5;
	}
	else
		link->ident->pos->y_pos -= link->ident->pos->speed * cos(PI / 180 *
										(link->ident->pos->dir + dir * 180.));
}

void		x_span(t_linker *link, float dir)
{
	int		ds;

	ds = (link->ident->pos->x_pos / MAP_SCALE + 1) * MAP_SCALE -
										link->ident->pos->x_pos;
	if (((link->ident->pos->speed * sin(PI / 180 * (link->ident->pos->dir + 180.
	* dir)) >= ds) && is_obstacle(link->map, link->ident->pos->x_pos / MAP_SCALE
	+ 1, link->ident->pos->y_pos / MAP_SCALE) == 1) || (link->ident->pos->speed
	* sin(PI / 180 * (link->ident->pos->dir + 180. * dir)) <= (ds = ds -
	MAP_SCALE) && is_obstacle(link->map, link->ident->pos->x_pos / MAP_SCALE
	- 1, link->ident->pos->y_pos / MAP_SCALE) == 1))
	{
		if (ds > MAP_SCALE / 5)
			link->ident->pos->x_pos += ds - MAP_SCALE / 5;
	}
	else
		link->ident->pos->x_pos += link->ident->pos->speed * sin(PI / 180 *
										(link->ident->pos->dir + 180. * dir));
}
