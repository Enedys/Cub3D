/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:31:49 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 18:59:06 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static float	sprite_height(t_linker *link, float dist)
{
	return (link->ident->res[1] * 1.0 * MAP_SCALE / dist);
}

static void		plot_v_spriteline(t_linker *link, int x0, float height, int j)
{
	int		i;
	int		y0;
	int		y_pixel;
	int		x_pixel;
	int		color;

	y0 = (link->ident->res[1] - height) / 2. + 0.17 * height;
	i = 0;
	if (y0 < 0)
		i = -y0 + 1;
	x_pixel = (j - x0) * link->texture->s->width * 1.0 / link->x_sprite_size;
	while (i < height)
	{
		if (i + y0 > link->ident->res[1])
			return ;
		y_pixel = i * link->texture->s->height * 1. / height;
		color = *((int *)get_pixel_ptr(link->texture->s, x_pixel, y_pixel));
		if (color != 0)
			set_pixel(link, j, y0 + i, color);
		i++;
	}
}

static void		plot_sprite(t_linker *link, int x0, int i)
{
	int		x;
	int		y;
	float	dist;
	int		j;
	float	height;

	x = x_sprite_pos(link->sprite_dist[i], link);
	y = y_sprite_pos(link->sprite_dist[i], link);
	dist = sqrt(pow(x - link->ident->pos->x_pos, 2) +
				pow(y - link->ident->pos->y_pos, 2));
	height = sprite_height(link, dist);
	link->x_sprite_size = 0.7 * (link->ident->res[0] * height / MAP_SCALE / 5) +
	0.6 * (4. * link->ident->pos->fov * sprite_height(link, dist) / MAP_SCALE);
	j = x0 - link->x_sprite_size / 2.;
	while (j < x0 + link->x_sprite_size / 2. && j < link->ident->res[0])
	{
		if (j >= 0 && dist < link->wall_dist[j])
			plot_v_spriteline(link, x0 - link->x_sprite_size / 2, height, j);
		j++;
	}
}

void			draw_sprite(t_linker *link)
{
	int		sprite_iter;
	float	sprite_angle;

	sprite_iter = 0;
	while (sprite_iter < link->sprite_num)
	{
		sprite_angle = atan2((x_sprite_pos(link->sprite_dist[sprite_iter], link)
			- link->ident->pos->x_pos), (link->ident->pos->y_pos -
			y_sprite_pos(link->sprite_dist[sprite_iter], link))) * 180. / PI;
		sprite_angle -= link->ident->pos->dir - link->ident->pos->fov / 2;
		while (sprite_angle < 0)
			sprite_angle += 360;
		while (sprite_angle > 360.)
			sprite_angle -= 360;
		if (sprite_angle > link->ident->pos->fov && sprite_angle > 180.)
			sprite_angle = -360 + sprite_angle;
		plot_sprite(link, sprite_angle * link->ident->res[0] /
					link->ident->pos->fov, sprite_iter);
		sprite_iter++;
	}
}
