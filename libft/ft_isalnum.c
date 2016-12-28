/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:46:21 by maxpetit          #+#    #+#             */
/*   Updated: 2016/07/27 11:08:30 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)) ||
	((c >= 48) && (c <= 57)))
		return (1);
	return (0);
}

int		ft_check_strisalnum(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (ft_isalnum(str[i]))
			return (0);
	return (1);
}
