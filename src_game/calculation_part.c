/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 00:07:17 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 18:58:41 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static float	height_calc(t_linker *link, float angle, int i)
{
	float	dist;
	float	size;

	dist = metric(link->collision->x0, link->collision->y0,
				link->collision->x1, link->collision->y1);
	link->wall_dist[i] = (int)dist;
	angle = link->ident->pos->dir - angle;
	size = link->ident->res[1] * MAP_SCALE / dist / cos(PI / 180. * angle);
	link->collision->height = size;
	return (size);
}

static void		find_barrier(t_linker *link, float angle)
{
	int			i;
	float		x;
	float		y;

	i = 0;
	link->collision->x1 = link->ident->pos->x_pos;
	link->collision->y1 = link->ident->pos->y_pos;
	while (i < DEPTH)
	{
		step_out(link, angle);
		x = link->collision->x1;
		y = link->collision->y1;
		if ((link->map)[(int)(y / MAP_SCALE)][(int)(x / MAP_SCALE)] == '1')
			break ;
	}
	link->collision->x0 = link->ident->pos->x_pos;
	link->collision->y0 = link->ident->pos->y_pos;
	link->collision->x1 = (int)x;
	link->collision->y1 = (int)y;
}

void			plot_interconnections(t_linker *link)
{
	float	height;
	float	angle;
	int		i;

	if (link->ident->save == 0)
	{
		mlx_destroy_image(link->mlx_ptr, link->img);
		create_image(link, link->ident->res[0], link->ident->res[1]);
	}
	angle = link->ident->pos->dir - link->ident->pos->fov / 2;
	refresh_plane(link);
	i = 0;
	while (i < link->ident->res[0])
	{
		angle += link->ident->pos->fov / link->ident->res[0];
		find_barrier(link, angle);
		height = height_calc(link, angle, i);
		draw_sky(link, i, (link->ident->res[1] - height) / 2);
		draw_wall(link, i, (link->ident->res[1] - height) / 2);
		i += 1;
	}
	draw_sprite(link);
	if (link->gun_regime % 2 == 1)
		draw_weapon(link);
}
