/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <maxpetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 12:25:09 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/28 18:51:22 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_recursive_power(int nb, int power)
{
	int res;

	res = nb;
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power < 0)
		return (0);
	res = nb * (ft_recursive_power(nb, power - 1));
	return (res);
}

int		ft_convert(char *nbr, char *base_from)
{
	int i;
	int j;
	int len_pre;
	int power;
	int num;

	i = 0;
	j = 0;
	num = 0;
	len_pre = ft_strlen(base_from);
	power = ft_strlen(nbr);
	while (nbr[j])
	{
		while (nbr[j] != base_from[i])
			i++;
		num = num + (i * (ft_recursive_power(len_pre, power - 1)));
		j++;
		i = 0;
		power--;
	}
	return (num);
}

char	*ft_count_size(char *nbr, char *base_from, char *base_to)
{
	int			i;
	int			num;
	int			size;
	char		*res;

	i = 0;
	num = ft_convert(nbr, base_from);
	while (num != 0)
	{
		num = num / ft_strlen(base_to);
		i++;
	}
	size = i;
	num = ft_convert(nbr, base_from);
	if (!(res = (char*)malloc(sizeof(*res) * size + 1)))
		return (NULL);
	res[size] = '\0';
	size--;
	while (0 <= size)
	{
		res[size] = base_to[num % ft_strlen(base_to)];
		num = num / ft_strlen(base_to);
		size--;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		num;

	num = ft_convert(nbr, base_from);
	if (num == 0)
	{
		if (!(res = (char*)malloc(sizeof(*res) * 1 + 1)))
			return (NULL);
		res[0] = base_to[0];
		res[1] = '\0';
	}
	else
		res = ft_count_size(nbr, base_from, base_to);
	return (res);
}
