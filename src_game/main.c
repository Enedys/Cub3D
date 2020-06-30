/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 23:09:32 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 18:59:28 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

t_linker	*initialize_game(int argc, char **argv)
{
	char				**map;
	t_identifier		*ident;
	t_linker			*link;

	ident = (t_identifier *)malloc(sizeof(t_identifier));
	map = get_map(argc, argv, ident);
	if (!map)
		free_identifiers(ident, INVALID_MAP_ERROR);
	link = create_linker_struct(ident, map);
	set_params(link);
	calculate_const(link);
	initialize_window(link);
	create_image(link, link->ident->res[0], link->ident->res[1]);
	load_textures(link);
	link->ident->pos->fov = 45 + (70 - 45) *\
				link->ident->res[0] / 1600.;
	return (link);
}

int			main(int argc, char **argv)
{
	t_linker		*link;

	link = initialize_game(argc, argv);
	plot_map(link);
	mlx_hook(link->win_ptr, 2, 1L << 0, key_event, link);
	mlx_hook(link->win_ptr, 17, 1L << 17, close_event, link);
	mlx_loop(link->mlx_ptr);
	return (0);
}
