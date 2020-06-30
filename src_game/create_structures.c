/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 01:33:25 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 18:58:53 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void		create_image(t_linker *link, int width, int height)
{
	link->img = mlx_new_image(link->mlx_ptr, width, height);
	if (!link->img)
		free_link(link, ALLOC_ERROR);
	link->data = mlx_get_data_addr(link->img, &link->bpp,
							&link->sizeline, &link->endian);
	if (!link->data)
		free_link(link, ALLOC_ERROR);
}

void		initialize_window(t_linker *link)
{
	int		x_res;
	int		y_res;

	link->mlx_ptr = mlx_init();
	if (!link->mlx_ptr)
		free_link(link, ALLOC_ERROR);
	mlx_get_screen_size(link->mlx_ptr, &x_res, &y_res);
	link->ident->res[0] > x_res ? link->ident->res[0] = x_res : 0;
	link->ident->res[1] > y_res ? link->ident->res[1] = y_res : 0;
	if (link->ident->save == 0)
	{
		link->win_ptr = mlx_new_window(link->mlx_ptr, link->ident->res[0],
								link->ident->res[1], "Kwillum's game");
		if (!link->win_ptr)
			free_link(link, ALLOC_ERROR);
	}
	else
		link->win_ptr = NULL;
}

int			calculate_const(t_linker *link)
{
	int		i;

	link->g->bsin = (float *)malloc(sizeof(float) * 360 * 60);
	link->g->bcos = (float *)malloc(sizeof(float) * 360 * 60);
	link->g->btan = (float *)malloc(sizeof(float) * 360 * 60);
	if (!link->g->bsin || !link->g->bcos || !link->g->btan)
		free_link(link, ALLOC_ERROR);
	i = 0;
	while (i < 360 * 60)
	{
		link->g->bsin[i] = sin(PI / 180. * i / 60.);
		link->g->bcos[i] = cos(PI / 180. * i / 60.);
		link->g->btan[i] = (link->g->bcos[i] != 0 ?
		link->g->bsin[i] / link->g->bcos[i] : 0.);
		i++;
	}
	return (1);
}

t_linker	*create_linker_struct(t_identifier *ident, char **map)
{
	t_linker			*link;

	if (!(link = (t_linker *)malloc(sizeof(t_linker))))
	{
		free_tab(map, -1);
		free_identifiers(ident, ALLOC_ERROR);
	}
	link->ident = ident;
	link->ident->pos = (t_position *)malloc(sizeof(t_position));
	link->collision = (t_collision_line *)malloc(sizeof(t_collision_line));
	link->texture = (t_texture *)malloc(sizeof(t_texture));
	link->g = (t_geomrtry *)malloc(sizeof(t_geomrtry));
	link->map = map;
	if (!link->ident->pos || !link->collision || !link->texture || !link->g)
		free_link(link, ALLOC_ERROR);
	return (link);
}
