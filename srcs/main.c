/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:57:01 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/29 15:49:08 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_tabi(t_data *data)
{
	int		i;

	i = -1;
	while (++i < LEN_Y)
	{
		free(data->tabi[i]);
		data->tabi[i] = NULL;
	}
}

void	ft_initialize_data(t_data *data, char *name, int mode)
{
	if (mode)
	{
		ft_bzero((void *)data, sizeof(t_data));
		LEN_X = 0;
		LEN_Y = 0;
		CTE1 = 0.5;
		CTE2 = 0.5;
		ZOOM = 10;
		H = -2;
		DIAGO = 0;
	}
	else
	{
		data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx, S_W_X, S_W_Y, name);
	}
}

void	fdf(char *argv)
{
	t_data	data;

	ft_initialize_data(&data, argv, 1);
	if (!ft_check_map_valid(argv, &data))
		return ;
	if (!ft_get_map(argv, &data))
		return ;
	ft_initialize_data(&data, argv, 0);
	mlx_loop_hook(data.mlx, ft_display, &data);
	mlx_hook(data.win, 2, (1L << 0), ft_key, &data);
	mlx_loop(data.mlx);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	else
		fdf(argv[1]);
	return (0);
}
