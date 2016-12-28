/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 21:13:35 by maxpetit          #+#    #+#             */
/*   Updated: 2016/07/20 13:06:47 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_tab(char **tab)
{
	int		i;
	int		j;
	char	**new;

	if (tab)
	{
		i = ft_strlen_tab(tab);
		if (!((new) = (char **)ft_memalloc(sizeof(char*) * (i + 1))))
			return (NULL);
		i = 0;
		j = 0;
		while (tab[i])
		{
			if (!((new[j]) = ft_strdup(tab[i])))
				return (NULL);
			j++;
			i++;
		}
		new[i] = NULL;
		return (new);
	}
	return (NULL);
}
