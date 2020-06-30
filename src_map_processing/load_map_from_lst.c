/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_from_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 20:29:31 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 19:00:07 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int		connect_line(char **map, int len, int pos)
{
	int		i;
	char	*s;

	i = 0;
	if (!map)
		return (-1);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
	{
		free_tab(map, pos);
		return (-1);
	}
	while (i < len)
	{
		s[i] = '.';
		i++;
	}
	s[i] = '\0';
	map[pos] = s;
	return (1);
}

static int		process_sline(char *lst_str, char **f_map, int i)
{
	int	j;

	j = 0;
	f_map[i][0] = '.';
	while (lst_str[j])
	{
		if (ft_isspaces(lst_str[j]) == 1)
			f_map[i][j + 1] = '.';
		else if (valid_param(lst_str[j]) == 1)
			f_map[i][j + 1] = lst_str[j];
		else
			f_map[i][j + 1] = 'i';
		j++;
	}
	return (j);
}

static void		infill_end_line(int j, int i, char **f_map, int params[2])
{
	while (j < params[1])
	{
		f_map[i][j] = '.';
		j++;
	}
	f_map[i][j] = '\0';
}

char			**get_final_map(int *params, t_list *lst)
{
	int		i;
	int		j;
	char	**f_map;
	char	*lst_str;

	f_map = (char **)malloc(sizeof(char *) * (params[0] + 1));
	if (connect_line(f_map, params[1], 0) == -1)
		return (NULL);
	i = 1;
	while (i < params[0] - 1)
	{
		lst_str = lst->content;
		lst = lst->next;
		j = 0;
		f_map[i] = (char *)malloc(sizeof(char) * (params[1] + 1));
		if (!f_map[i])
			return (free_tab(f_map, i));
		j = process_sline(lst_str, f_map, i) + 1;
		infill_end_line(j, i, f_map, params);
		i++;
	}
	if (connect_line(f_map, params[1], i) == -1)
		return (NULL);
	f_map[i + 1] = NULL;
	return (f_map);
}
