/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_processing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:04:25 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 19:00:01 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

char	*scip_spaces(char *s)
{
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\f' ||
			*s == '\r' || *s == '\t' || *s == '\v')
		s++;
	return (s);
}

void	set_identifiers(t_identifier *ident)
{
	ident->flags = 0;
	ident->ea_path = NULL;
	ident->no_path = NULL;
	ident->so_path = NULL;
	ident->we_path = NULL;
	ident->s_path = NULL;
	ident->f_color[0] = 0;
	ident->f_color[1] = 0;
	ident->f_color[2] = 0;
	ident->c_color[0] = 0;
	ident->c_color[1] = 0;
	ident->c_color[2] = 0;
	ident->res[0] = 0;
	ident->res[1] = 0;
	ident->save = 0;
	ident->pos = NULL;
	ident->map_x_dim = 0;
	ident->map_y_dim = 0;
}

void	*free_tab(char **tab, int final)
{
	int	iter;

	iter = 0;
	if (final < 0)
		final = 2147483647;
	while (tab[iter] && iter <= final)
	{
		free(tab[iter]);
		iter++;
	}
	free(tab);
	return (NULL);
}

int		tab_length(char **tab)
{
	int	iter;

	iter = 0;
	while (tab[iter])
		iter++;
	if (iter < 2 || iter > 3)
	{
		free_tab(tab, -1);
		return (-1);
	}
	return (iter);
}

int		valid_param(int c)
{
	const char	*s = "102SNWE";
	int			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
