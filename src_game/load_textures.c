/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:42:52 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 18:59:25 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void		free_tex(t_tex *tex, void *mlx_ptr)
{
	if (tex)
	{
		mlx_destroy_image(mlx_ptr, tex->img_ptr);
		free(tex);
	}
}

void			free_texture(t_linker *link)
{
	free_tex(link->texture->ea, link->mlx_ptr);
	free_tex(link->texture->floor, link->mlx_ptr);
	free_tex(link->texture->no, link->mlx_ptr);
	free_tex(link->texture->s, link->mlx_ptr);
	free_tex(link->texture->sky, link->mlx_ptr);
	free_tex(link->texture->so, link->mlx_ptr);
	free_tex(link->texture->we, link->mlx_ptr);
	free_tex(link->texture->weapon, link->mlx_ptr);
	free(link->texture);
}

static t_tex	*load_texture(t_linker *link, char *path)
{
	t_tex	*texture;

	texture = (t_tex *)malloc(sizeof(t_tex));
	if (!texture)
		return (NULL);
	texture->img_ptr = mlx_xpm_file_to_image(link->mlx_ptr, path,
						&texture->width, &texture->height);
	if (!texture->img_ptr)
	{
		free(texture);
		return (NULL);
	}
	texture->data_ptr = mlx_get_data_addr(texture->img_ptr, &texture->bpp,
						&texture->sizeline, &texture->endian);
	return (texture);
}

void			load_textures(t_linker *link)
{
	t_texture	*texture;

	texture = link->texture;
	texture->sky = load_texture(link, "./texture/cyber4.xpm");
	texture->floor = load_texture(link, "./texture/10.xpm");
	texture->weapon = load_texture(link, "./texture/weapon1.xpm");
	texture->s = load_texture(link, link->ident->s_path);
	texture->so = load_texture(link, link->ident->so_path);
	texture->no = load_texture(link, link->ident->no_path);
	texture->we = load_texture(link, link->ident->we_path);
	texture->ea = load_texture(link, link->ident->ea_path);
	if (!texture->sky || !texture->floor || !texture->weapon || !texture->s \
	|| !texture->so || !texture->no || !texture->we || !texture->ea)
		free_link(link, TEXTURE_ERROR);
}
