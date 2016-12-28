/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:01:57 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/28 20:27:41 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_isox(t_data *data, t_coord c)
{
	int	x;

	c.x *= ZOOM;
	c.y *= ZOOM;
	x = (CTE1 * c.x - CTE2 * c.y) + (S_W_X / 2);
	return (x);
}

int		ft_isoy(t_data *data, t_coord c)
{
	int	y;

	c.x *= ZOOM;
	c.y *= ZOOM;
	c.z *= ZOOM / 3;
	y = (c.z * H) + (CTE1 / 2) * c.x + (CTE2 / 2) * c.y + (S_W_Y / 2);
	return (y);
}

void	ft_manage_line(t_data *data, t_coord c1, t_coord c2)
{
	t_line line;

	line.x1 = ft_isox(data, c1);
	line.y1 = ft_isoy(data, c1);
	line.x2 = ft_isox(data, c2);
	line.y2 = ft_isoy(data, c2);
	line.dx = line.x2 - line.x1;
	line.dy = line.y2 - line.y1;
	line.xinc = (line.dx > 0) ? 1 : -1;
	line.yinc = (line.dy > 0) ? 1 : -1;
	line.dx = (line.dx < 0) ? line.dx * -1 : line.dx;
	line.dy = (line.dy < 0) ? line.dy * -1 : line.dy;
	mlx_pixel_put(data->mlx, data->win, line.x1, line.y1, c1.color);
	if (line.dx > line.dy)
		ft_trace_line(data, &line, HORIZONTAL, c1.color);
	else
		ft_trace_line(data, &line, VERTICAL, c1.color);
}

void	ft_trace_line(t_data *data, t_line *line, int mode, int color)
{
	int			i;
	t_tmp_line	tmp;

	i = -1;
	C_P = (!mode) ? line->x1 : line->y1;
	C_S = (!mode) ? line->y1 : line->x1;
	D_P = (!mode) ? line->dx : line->dy;
	D_S = (!mode) ? line->dy : line->dx;
	I_P = (!mode) ? line->xinc : line->yinc;
	I_S = (!mode) ? line->yinc : line->xinc;
	line->cumul = D_P / 2;
	while (++i < D_P)
	{
		C_P += I_P;
		line->cumul += D_S;
		if (line->cumul >= D_P)
		{
			line->cumul -= D_P;
			C_S += I_S;
		}
		line->x1 = (!mode) ? C_P : C_S;
		line->y1 = (!mode) ? C_S : C_P;
		mlx_pixel_put(data->mlx, data->win, line->x1, line->y1, color);
	}
}
