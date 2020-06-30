/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regime_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:42:37 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 19:57:50 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void		set_params(t_linker *link)
{
	link->mlx_ptr = NULL;
	link->g->bsin = NULL;
	link->g->bcos = NULL;
	link->g->btan = NULL;
	link->sprite_dist = NULL;
	link->wall_dist = NULL;
	link->img = NULL;
	link->texture->ea = NULL;
	link->texture->floor = NULL;
	link->texture->no = NULL;
	link->texture->s = NULL;
	link->texture->sky = NULL;
	link->texture->so = NULL;
	link->texture->we = NULL;
	link->texture->weapon = NULL;
	link->sky_regime = 1;
	link->wall_regime = 1;
	link->floor_regime = 1;
	link->floor_reflection = 1;
	link->gun_regime = 1;
	link->ident->pos->speed = 50;
}

int			key_event(int key_num, void *s_ptr)
{
	t_linker	*link;

	link = (t_linker *)s_ptr;
	if (key_num == 65307)
		free_link(link, CORRECT_EXIT);
	rotate_events(link, key_num);
	move_events(link, key_num);
	plot_interconnections(link);
	mlx_put_image_to_window(link->mlx_ptr, link->win_ptr, link->img, 0, 0);
	return (1);
}
