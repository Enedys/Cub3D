/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:18:21 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 18:59:50 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

float		metric(int x0, int y0, int x1, int y1)
{
	float	res;

	res = sqrt(pow(x0 - x1, 2.) + pow(y0 - y1, 2.));
	return (res);
}

int			y_sprite_pos(int y, t_linker *link)
{
	return ((y / link->ident->map_x_dim) * MAP_SCALE + MAP_SCALE / 2);
}

int			x_sprite_pos(int x, t_linker *link)
{
	return ((x - (x / link->ident->map_x_dim) * link->ident->map_x_dim)
			* MAP_SCALE + MAP_SCALE / 2);
}

int			calc_angle_index(float angle)
{
	return ((int)(angle) * 60 + (int)((angle - (int)angle) * 60));
}

void		refresh_plane(t_linker *link)
{
	link->collision->x_dir_plane = sin(PI / 180. * (link->ident->pos->dir -
	link->ident->pos->fov / 2)) / sin(PI / 180. * link->ident->pos->fov / 2);
	link->collision->y_dir_plane = cos(PI / 180. * (link->ident->pos->dir -
	link->ident->pos->fov / 2)) / sin(PI / 180. * link->ident->pos->fov / 2);
	link->collision->a_index = calc_angle_index(link->ident->pos->dir);
}
