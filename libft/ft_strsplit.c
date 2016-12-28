/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <maxpetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 10:23:07 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/13 11:09:46 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**add_tab(char **tab, int size_tab)
{
	char	**new_tab;

	if (!(new_tab = (char**)malloc(sizeof(char*) * (size_tab + 1))))
		return (0);
	new_tab[size_tab] = NULL;
	if (size_tab == 1)
		return (new_tab);
	size_tab -= 2;
	while (size_tab >= 0)
	{
		new_tab[size_tab] = tab[size_tab];
		size_tab--;
	}
	return (new_tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	**tmp;
	int		size;
	int		size_tab;

	if (!(tab = (char**)malloc(sizeof(char*))))
		return (NULL);
	*tab = NULL;
	size_tab = 0;
	while (*s)
	{
		while (!(size = ft_strlenc((char*)s, c)))
			s++;
		if (size == -1)
			return (tab);
		tmp = tab;
		tab = add_tab(tab, ++size_tab);
		free(tmp);
		tab[size_tab - 1] = ft_strncpy(ft_strnew(size), s, size);
		s += size;
	}
	return (tab);
}
