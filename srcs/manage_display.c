/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:44:03 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/28 20:28:33 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_display(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < LEN_Y)
	{
		j = -1;
		while (++j < LEN_X)
		{
			if (j + 1 != LEN_X)
				ft_manage_line(data, data->tabi[i][j], data->tabi[i][JNXT]);
			if (i + 1 != LEN_Y)
				ft_manage_line(data, data->tabi[i][j], data->tabi[INXT][j]);
			if (DIAGO && ((i + 1 != LEN_Y) && (j + 1 != LEN_X)))
				ft_manage_line(data, data->tabi[i][j], data->tabi[INXT][JNXT]);
		}
	}
	return (0);
}

void	ft_reinitialise_screen(t_data *data)
{
	int i;
	int j;

	j = -1;
	while (++j < S_W_X)
	{
		i = -1;
		while (++i < S_W_Y)
			mlx_pixel_put(data->mlx, data->win, j, i, 0x000000);
	}
}
