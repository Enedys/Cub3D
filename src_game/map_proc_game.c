/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_proc_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 00:57:52 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 23:37:13 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int		valid_symbols(int c, int i, int j, t_identifier *ident)
{
	const char	*s = "2";
	const char	*p = "SWNEP";
	int			k;

	if (*s == (char)c)
		return (1);
	k = 0;
	while (p[k])
	{
		if (p[k++] == (char)c && c != 'P')
		{
			ident->pos->x_pos = j * MAP_SCALE;
			ident->pos->y_pos = i * MAP_SCALE;
			if (c == 'N')
				ident->pos->dir = 0;
			if (c == 'S')
				ident->pos->dir = 180;
			if (c == 'W')
				ident->pos->dir = 270;
			if (c == 'E')
				ident->pos->dir = 90;
			return (2);
		}
	}
	return (0);
}

static void		allocate_sprite_list(t_linker *link, int nbr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	link->sprite_dist = (int *)malloc(sizeof(int) * (nbr));
	link->wall_dist = (int *)malloc(sizeof(int) * (link->ident->res[0]));
	link->sprite_num = nbr;
	if (!link->sprite_dist || !link->wall_dist)
		free_link(link, ALLOC_ERROR);
	while (i < link->ident->map_y_dim)
	{
		j = 0;
		while (j < link->ident->map_x_dim)
		{
			if (valid_symbols(link->map[i][j], i, j, link->ident) == 1)
				link->sprite_dist[k++] = link->ident->map_x_dim * i + j;
			j++;
		}
		i++;
	}
}

static	void	make_screenshot(t_linker *link)
{
	t_uchar		*bmp;
	int			fd;
	int			size;

	size = link->ident->res[0] * link->ident->res[1] * link->bpp / 8 + 54;
	if (!(bmp = (t_uchar *)malloc(sizeof(char) * size)))
		free_link(link, ALLOC_ERROR);
	ft_bzero(bmp, size);
	ft_memcpy(&bmp[0], "BM", 2);
	fd = 54;
	ft_memcpy(&bmp[10], &fd, 4);
	fd = 40;
	ft_memcpy(&bmp[14], &fd, 4);
	ft_memcpy(&bmp[18], &link->ident->res[0], 4);
	fd = -link->ident->res[1];
	ft_memcpy(&bmp[22], &fd, 4);
	fd = 1;
	ft_memcpy(&bmp[26], &fd, 2);
	ft_memcpy(&bmp[28], &link->bpp, 2);
	ft_memcpy(&bmp[54], link->data, size - 54);
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	fd = write(fd, bmp, size);
	free(bmp);
	close(fd);
	fd < 0 ? free_link(link, ALLOC_ERROR) : free_link(link, CORRECT_EXIT);
}

void			plot_map(t_linker *link)
{
	int	i;
	int	j;
	int	sprite_counter;
	int	res;

	i = 0;
	sprite_counter = 0;
	while (i < link->ident->map_y_dim)
	{
		j = 0;
		while (j < link->ident->map_x_dim)
		{
			if ((res = valid_symbols(link->map[i][j], i, j, link->ident)) == 1)
				sprite_counter++;
			else if (res == 2)
				link->map[i][j] = '0';
			j++;
		}
		i++;
	}
	allocate_sprite_list(link, sprite_counter);
	plot_interconnections(link);
	if (link->ident->save == 1)
		make_screenshot(link);
}
