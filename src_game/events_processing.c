/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 22:42:19 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 23:40:47 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	move_events(t_linker *link, int key_num)
{
	if (key_num == 119)
	{
		y_span(link, 0);
		x_span(link, 0);
		buble_sort(link->sprite_dist, link);
	}
	if (key_num == 115)
	{
		x_span(link, 1);
		y_span(link, 1);
		buble_sort(link->sprite_dist, link);
	}
	if (key_num == 100)
	{
		x_span(link, 0.5);
		y_span(link, 0.5);
		buble_sort(link->sprite_dist, link);
	}
	if (key_num == 97)
	{
		x_span(link, 1.5);
		y_span(link, 1.5);
		buble_sort(link->sprite_dist, link);
	}
}

void	rotate_events(t_linker *link, int key_num)
{
	if (key_num == 65363)
	{
		link->ident->pos->dir += ANGLE_STEP;
		if (link->ident->pos->dir >= 360)
			link->ident->pos->dir -= 360;
	}
	if (key_num == 65361)
	{
		link->ident->pos->dir -= ANGLE_STEP;
		if (link->ident->pos->dir < 0)
			link->ident->pos->dir += 360;
	}
}

int		close_event(void *s_ptr)
{
	t_linker	*link;

	link = (t_linker *)s_ptr;
	free_link(link, CORRECT_EXIT);
	return (1);
}
