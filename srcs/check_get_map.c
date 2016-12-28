/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 15:14:44 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/29 15:49:07 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_map_valid(char *path, t_data *data)
{
	int		ret;
	int		fd;
	char	*line;

	line = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		ft_putstr_fd("OPEN ERROR\n", 2);
		return (0);
	}
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < 0)
			return (0);
		LEN_Y++;
	}
	if (!LEN_Y && ret == 0)
	{
		ft_putstr_fd("MAP ERROR\n", 2);
		return (0);
	}
	close(fd);
	return (1);
}

int		ft_ret_index(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}

void	ft_initialize_coord(t_data *data, char *str, int i, int j)
{
	char		*color;
	char		*color_hex;
	char		*nb;
	char		*dec;
	char		*hex;

	dec = "0123456789";
	hex = "0123456789ABCDEF";
	color = ft_strchr(str, ',');
	if (color && (color_hex = ft_convert_base(color, hex, dec)))
	{
		color++;
		nb = ft_strnew(ft_ret_index(str, ','));
		nb = ft_strncpy(nb, str, ft_ret_index(str, ','));
	}
	nb = (!color) ? str : nb;
	X = j;
	Y = i;
	Z = ft_atoi(nb);
	COLOR = (!color) ? 0xF9429E : ft_atoi(color_hex);
	if (color)
	{
		ft_strdel(&nb);
		ft_strdel(&color_hex);
	}
}

int		ft_initialize_tabline(t_data *data, char *line)
{
	static int	i;
	int			j;
	char		**tmp;

	j = -1;
	tmp = ft_strsplit(line, ' ');
	LEN_X = (!LEN_X) ? ft_strlen_tab(tmp) : LEN_X;
	if (LEN_X != ft_strlen_tab(tmp))
	{
		ft_putstr_fd("MAP ERROR\n", 2);
		return (0);
	}
	if (!i)
		while (++j < LEN_Y)
			data->tabi[j] = (t_coord *)ft_memalloc(sizeof(t_coord) * LEN_X);
	j = -1;
	S_W_X = (LEN_X <= 12) ? LEN_X * 40 : LEN_X * 20;
	S_W_Y = (LEN_Y <= 12) ? LEN_Y * 40 : LEN_Y * 20;
	if ((S_W_X > 1000 || S_W_Y > 1000) && (S_W_X = 1000))
		S_W_Y = 1000;
	while (tmp[++j])
		ft_initialize_coord(data, tmp[j], i, j);
	ft_free_tab(&tmp);
	i++;
	return (1);
}

int		ft_get_map(char *path, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	line = NULL;
	data->tabi = (t_coord **)ft_memalloc(sizeof(t_coord *) * LEN_Y);
	if ((fd = open(path, O_RDONLY)) == -1)
		strerror(fd);
	while (get_next_line(fd, &line))
	{
		if (!ft_initialize_tabline(data, line))
			return (0);
		free(line);
		line = NULL;
	}
	close(fd);
	return (1);
}
