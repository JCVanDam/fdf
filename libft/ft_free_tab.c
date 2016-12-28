/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 21:15:40 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/28 20:26:46 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char ***tab)
{
	int		i;
	char	**tmp;

	i = -1;
	tmp = *tab;
	while (tmp[++i])
	{
		ft_strdel(&((*tab)[i]));
		(*tab)[i] = NULL;
	}
	free(*tab);
	*tab = NULL;
}

void	ft_free_tab3dim(char ****tab)
{
	int		i;
	char	***tmp;

	i = -1;
	tmp = *tab;
	while (tmp[++i])
	{
		ft_free_tab(&((*tab)[i]));
		free((*tab)[i]);
	}
	free(*tab);
	*tab = NULL;
}
