/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regime_creative_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:46:02 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 22:38:26 by Kwillum          ###   ########.fr       */
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
	link->sky_regime = 0;
	link->wall_regime = 0;
	link->floor_regime = 0;
	link->floor_reflection = 0;
	link->gun_regime = 0;
	link->ident->pos->speed = 50;
}

static void	bonus_events(t_linker *link, int key_num)
{
	if (key_num == 110)
		link->sky_regime++;
	if (key_num == 101)
		link->wall_regime++;
	if (key_num == 114)
		link->floor_reflection++;
	if (key_num == 102)
		link->floor_regime++;
	if (key_num == 103)
		link->gun_regime++;
}

int			key_event(int key_num, void *s_ptr)
{
	t_linker	*link;

	link = (t_linker *)s_ptr;
	if (key_num == 65307)
		free_link(link, CORRECT_EXIT);
	rotate_events(link, key_num);
	move_events(link, key_num);
	bonus_events(link, key_num);
	plot_interconnections(link);
	mlx_put_image_to_window(link->mlx_ptr, link->win_ptr, link->img, 0, 0);
	return (1);
}
