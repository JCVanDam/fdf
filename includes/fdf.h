/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:54:25 by maxpetit          #+#    #+#             */
/*   Updated: 2016/12/28 17:26:43 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# define HORIZONTAL 0
# define VERTICAL	1
# define LEN_X		data->len_x
# define LEN_Y		data->len_y
# define X			data->tabi[i][j].x
# define Y			data->tabi[i][j].y
# define Z			data->tabi[i][j].z
# define COLOR		data->tabi[i][j].color
# define ZOOM		data->zoom
# define S_W_X		data->size_window_x
# define S_W_Y		data->size_window_y
# define H			data->height
# define CTE1		data->cte1
# define CTE2		data->cte2
# define DIAGO		data->diago
# define C_P		tmp.c_princ
# define C_S		tmp.c_sec
# define D_P		tmp.d_princ
# define D_S		tmp.d_sec
# define I_P		tmp.inc_princ
# define I_S		tmp.inc_sec
# define INXT		i + 1
# define JNXT		j + 1

typedef struct	s_tmp_line
{
	int			c_princ;
	int			c_sec;
	int			d_princ;
	int			d_sec;
	int			inc_princ;
	int			inc_sec;
}				t_tmp_line;

typedef struct	s_line
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
	int			cumul;
}				t_line;

typedef struct	s_coord
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_coord;

typedef struct	s_data
{
	int			len_x;
	int			len_y;
	float		cte1;
	float		cte2;
	void		*mlx;
	void		*win;
	int			zoom;
	int			size_window_x;
	int			size_window_y;
	int			height;
	int			diago;
	t_coord		**tabi;
}				t_data;

/*
**event.c
*/
int				ft_key(int keycode, t_data *data);
int				ft_key_cte_zoom(int keycode, t_data *data);
/*
**main.c
*/
void			ft_free_tabi(t_data *data);
void			ft_initialize_data(t_data *data, char *name, int mode);
void			fdf(char *argv);
/*
**draw_line.c
*/
void			ft_manage_line(t_data *data, t_coord c1, t_coord c2);
void			ft_trace_line(t_data *data, t_line *line, int mode, int i);
int				ft_isox(t_data *data, t_coord c);
int				ft_isoy(t_data *data, t_coord c);
/*
**manage_display.c
*/
int				ft_display(t_data *data);
void			ft_reinitialise_screen(t_data *data);
/*
**check_get_map.c
*/
int				ft_check_map_valid(char *path, t_data *data);
int				ft_initialize_tabline(t_data *data, char *line);
int				ft_get_map(char *path, t_data *data);
void			ft_initialize_coord(t_data *data, char *str, int i, int j);
int				ft_ret_index(char *str, char c);
/*
**convert_base.c
*/
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);

#endif
