/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 12:50:29 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/29 14:32:14 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key(int keycode, t_data *data)
{
	ft_reinitialise_screen(data);
	if (keycode == 53)
	{
		ft_free_tabi(data);
		exit(0);
	}
	if (keycode == 125)
		H++;
	if (keycode == 126)
		H--;
	if (keycode == 2)
	{
		if (!DIAGO)
			DIAGO = 1;
		else
			DIAGO = 0;
	}
	ft_key_cte_zoom(keycode, data);
	return (0);
}

int		ft_key_cte_zoom(int keycode, t_data *data)
{
	if (keycode == 12)
		CTE1 += 0.1;
	if (keycode == 0)
		CTE1 -= 0.1;
	if (keycode == 13)
		CTE2 += 0.1;
	if (keycode == 1)
		CTE2 -= 0.1;
	if (keycode == 6)
		ZOOM *= 2;
	if (keycode == 7)
		ZOOM /= 2;
	if (keycode == 49)
	{
		CTE1 = 0.5;
		CTE2 = 0.5;
		ZOOM = 10;
		H = -2;
		DIAGO = 0;
	}
	return (0);
}
