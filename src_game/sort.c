/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:13:10 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 18:59:55 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

static int	metrics(int a, int cur, t_linker *link)
{
	int	x_cur;
	int	y_cur;
	int	x1;
	int	y1;

	y_cur = y_sprite_pos(cur, link);
	x_cur = x_sprite_pos(cur, link);
	y1 = y_sprite_pos(a, link);
	x1 = x_sprite_pos(a, link);
	if (metric(x_cur, y_cur, link->ident->pos->x_pos, link->ident->pos->y_pos)
	<= metric(x1, y1, link->ident->pos->x_pos, link->ident->pos->y_pos))
		return (1);
	return (0);
}

static int	find_farest(int *arr, int i, t_linker *link)
{
	int	j;
	int	cur;

	j = i;
	cur = i;
	while (j < link->sprite_num)
	{
		if (metrics(arr[j], arr[cur], link) == 1)
			cur = j;
		j++;
	}
	return (cur);
}

void		buble_sort(int *arr, t_linker *link)
{
	int	i;
	int	j;

	i = 0;
	while (i < link->sprite_num - 1)
	{
		j = find_farest(arr, i, link);
		ft_swap(&arr[j], &arr[i]);
		i++;
	}
}
