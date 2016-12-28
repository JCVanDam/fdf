/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 15:20:54 by maxpetit          #+#    #+#             */
/*   Updated: 2016/08/14 16:03:59 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_padding(char orientation, char *str, size_t size, char elem)
{
	size_t	i;
	char	*new;

	if ((size_t)ft_strlen(str) != size)
	{
		i = (orientation == 'L') ? 0 : (size_t)ft_strlen(str);
		new = ft_strnew((int)size);
		if (orientation == 'R')
			new = ft_strcpy(new, str);
		while ((size_t)ft_strlen(str) != size)
		{
			new[i] = elem;
			i++;
			size--;
		}
		if (orientation == 'L')
			new = ft_strcat(new, str);
		return (new);
	}
	return (str);
}
