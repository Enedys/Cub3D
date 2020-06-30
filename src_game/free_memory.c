/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 01:26:53 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 18:59:15 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	free_g(t_geomrtry *g)
{
	if (g->bcos)
		free(g->bcos);
	if (g->bsin)
		free(g->bsin);
	if (g->btan)
		free(g->btan);
	free(g);
}

void		free_identifiers(t_identifier *ident, int er_num)
{
	if (er_num == INVALID_MAP_ERROR)
		ft_putstr_fd("Error\nMap error.\n", 2);
	else if (er_num == ALLOC_ERROR)
		ft_putstr_fd("Error\nStruct allocation error.\n", 2);
	else if (er_num == TEXTURE_ERROR)
		ft_putstr_fd("Error\nTexture problem.\n", 2);
	if (ident->ea_path != NULL)
		free(ident->ea_path);
	if (ident->no_path != NULL)
		free(ident->no_path);
	if (ident->we_path != NULL)
		free(ident->we_path);
	if (ident->so_path != NULL)
		free(ident->so_path);
	if (ident->s_path != NULL)
		free(ident->s_path);
	if (ident->pos != NULL)
		free(ident->pos);
	free(ident);
	exit(0);
}

void		free_link(t_linker *link, int er_num)
{
	t_identifier	*ident;

	if (link->sprite_dist)
		free(link->sprite_dist);
	if (link->wall_dist)
		free(link->wall_dist);
	if (link->collision)
		free(link->collision);
	if (link->g)
		free_g(link->g);
	if (link->texture)
		free_texture(link);
	if (link->img)
		mlx_destroy_image(link->mlx_ptr, link->img);
	if (link->mlx_ptr && link->win_ptr)
		mlx_destroy_window(link->mlx_ptr, link->win_ptr);
	if (link->mlx_ptr)
		free(link->mlx_ptr);
	ident = link->ident;
	free_tab(link->map, -1);
	free(link);
	free_identifiers(ident, er_num);
}
