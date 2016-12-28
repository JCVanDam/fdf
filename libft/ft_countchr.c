/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 19:33:09 by maxpetit          #+#    #+#             */
/*   Updated: 2016/07/25 16:58:08 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countchr(char *src, char c)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (src[++i])
	{
		if (src[i] == c)
			j++;
	}
	return (j);
}
