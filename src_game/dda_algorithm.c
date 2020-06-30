/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 22:54:34 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 18:58:57 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	calc_0_90_range(t_linker *link, t_collision_line *coll, int i)
{
	float	dx;
	float	dy;

	dy = coll->y1 - floor(coll->y1 / MAP_SCALE) * MAP_SCALE;
	dx = (floor(coll->x1 / MAP_SCALE) + 1) * MAP_SCALE - coll->x1;
	if (dy * link->g->btan[i] < dx)
	{
		dx = dy * link->g->btan[i];
		coll->x1 += dx;
		coll->y1 -= dy + 1;
		coll->side = 'u';
	}
	else
	{
		dy = dx * link->g->btan[90 * 60 - i];
		coll->x1 += dx;
		coll->y1 -= dy;
		coll->side = 'r';
	}
}

static void	calc_90_180_range(t_linker *link, t_collision_line *coll, int i)
{
	float	dx;
	float	dy;

	dy = (floor(coll->y1 / MAP_SCALE) + 1) * MAP_SCALE - coll->y1;
	dx = (floor(coll->x1 / MAP_SCALE) + 1) * MAP_SCALE - coll->x1;
	if (dx * link->g->btan[i - 90 * 60] < dy)
	{
		dy = dx * link->g->btan[i - 90 * 60];
		coll->x1 += dx;
		coll->y1 += dy;
		coll->side = 'r';
	}
	else
	{
		dx = dy * link->g->btan[180 * 60 - i];
		coll->y1 += dy;
		coll->x1 += dx;
		coll->side = 'd';
	}
}

static void	calc_180_270_range(t_linker *link, t_collision_line *coll, int i)
{
	float	dx;
	float	dy;

	dy = (floor(coll->y1 / MAP_SCALE) + 1) * MAP_SCALE - coll->y1;
	dx = coll->x1 - (floor(coll->x1 / MAP_SCALE)) * MAP_SCALE;
	if (dy * link->g->btan[i - 180 * 60] < dx)
	{
		dx = dy * link->g->btan[i - 180 * 60];
		coll->x1 -= dx;
		coll->y1 += dy;
		coll->side = 'd';
	}
	else
	{
		dy = dx * link->g->btan[270 * 60 - i];
		coll->y1 += dy;
		coll->x1 -= dx + 1;
		coll->side = 'l';
	}
}

static void	calc_270_360_range(t_linker *link, t_collision_line *coll, int i)
{
	float	dx;
	float	dy;

	dy = coll->y1 - (floor(coll->y1 / MAP_SCALE)) * MAP_SCALE;
	dx = coll->x1 - (floor(coll->x1 / MAP_SCALE)) * MAP_SCALE;
	if (dx * link->g->btan[i - 270 * 60] < dy)
	{
		dy = dx * link->g->btan[i - 270 * 60];
		coll->y1 -= dy;
		coll->x1 -= dx + 1;
		coll->side = 'l';
	}
	else
	{
		dx = dy * link->g->btan[360 * 60 - i];
		coll->y1 -= dy + 1;
		coll->x1 -= dx;
		coll->side = 'u';
	}
}

void		step_out(t_linker *link, float angle)
{
	int	i;

	if (angle < 0)
		angle += 360.;
	else if (angle >= 360)
		angle -= 360;
	i = calc_angle_index(angle);
	if (angle >= 0 && angle < 90)
		calc_0_90_range(link, link->collision, i);
	else if (angle >= 90 && angle < 180)
		calc_90_180_range(link, link->collision, i);
	else if (angle >= 180 && angle < 270)
		calc_180_270_range(link, link->collision, i);
	else
		calc_270_360_range(link, link->collision, i);
}
