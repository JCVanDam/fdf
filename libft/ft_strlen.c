/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:37:48 by maxpetit          #+#    #+#             */
/*   Updated: 2016/07/21 10:52:56 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlen_printable(char const *s)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] > 32 && s[i] < 127)
			j++;
		i++;
	}
	return (j);
}
