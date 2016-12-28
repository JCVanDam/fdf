/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_srch_idx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 21:18:21 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/06 16:35:03 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tab_srch_idx(char **tab, char *needle)
{
	int i;

	i = 0;
	if (tab && *tab)
	{
		while (tab[i])
		{
			if (ft_strstr(tab[i], needle))
				return (i);
			i++;
		}
	}
	return (-1);
}
