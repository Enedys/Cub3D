/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description_processing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:37:24 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/30 16:31:54 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	infill_array(char **tab, int *array, int n)
{
	int	iter;
	int	res;
	int	i;

	iter = 0;
	while (iter < n)
	{
		i = 0;
		while (tab[iter][i])
		{
			if (ft_isspaces(tab[iter][i]) != 1 &&
				ft_isdigit(tab[iter][i]) == 0)
				return (-1);
			i++;
		}
		res = catch_overflow(tab[iter]);
		if (res < 0 || (n == 3 && res > 255) ||
						(n == 2 && res == 0))
			return (-1);
		array[iter] = res;
		iter++;
	}
	return (1);
}

static int	process_num(char *s, unsigned char flag, t_identifier *ident)
{
	char	**tab;
	int		tab_len;
	int		res;

	if (refresh_flag(ident, flag) == -1)
		return (-1);
	if (flag == 128)
		tab = ft_split_spaces(s + 1);
	else
		tab = ft_split(s + 1, ',');
	if (!tab || (tab_len = tab_length(tab)) == -1)
		return (-1);
	if (flag == 128 && tab_len == 2)
		res = infill_array(tab, ident->res, 2);
	else if (flag == 64 && tab_len == 3)
		res = infill_array(tab, ident->f_color, 3);
	else if (flag == 32 && tab_len == 3)
		res = infill_array(tab, ident->c_color, 3);
	else
	{
		free_tab(tab, -1);
		return (-1);
	}
	free_tab(tab, -1);
	return (res);
}

static int	set_adress(char **s, char *src)
{
	int		fd;

	if (*s != NULL)
	{
		free(src);
		return (-1);
	}
	*s = src;
	if ((fd = open(src, O_RDONLY)) < 0)
		return (-1);
	close(fd);
	return (1);
}

static int	process_adress(char *s, unsigned char flag, t_identifier *ident)
{
	char	*adr;
	int		res;

	adr = ft_strtrim(flag == 16 ? s + 1 : s + 2, " \t\v\n\f\r");
	if (!adr)
		return (-1);
	if (flag == 1)
		res = set_adress(&(ident->no_path), adr);
	else if (flag == 2)
		res = set_adress(&(ident->so_path), adr);
	else if (flag == 4)
		res = set_adress(&(ident->we_path), adr);
	else if (flag == 8)
		res = set_adress(&(ident->ea_path), adr);
	else if (flag == 16)
		res = set_adress(&(ident->s_path), adr);
	ident->flags = ident->flags | flag;
	return (res);
}

int			define_identifier(char *s, t_identifier *ident)
{
	unsigned char	flag;

	flag = 0;
	if (*s == 'R')
		flag = 1 << 7;
	else if (*s == 'N' && *(s + 1) == 'O')
		flag = 1 << 0;
	else if (*s == 'S' && *(s + 1) == 'O')
		flag = 1 << 1;
	else if (*s == 'W' && *(s + 1) == 'E')
		flag = 1 << 2;
	else if (*s == 'E' && *(s + 1) == 'A')
		flag = 1 << 3;
	else if (*s == 'S')
		flag = 1 << 4;
	else if (*s == 'C')
		flag = 1 << 5;
	else if (*s == 'F')
		flag = 1 << 6;
	else if (*s == '\0')
		return (-2);
	else
		return (-1);
	return (flag <= 16 ? process_adress(s, flag, ident) : \
	process_num(s, flag, ident));
}
