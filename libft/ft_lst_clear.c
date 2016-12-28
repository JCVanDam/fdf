/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <maxpetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 15:05:09 by maxpetit          #+#    #+#             */
/*   Updated: 2016/07/21 13:27:40 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_clear(t_list **begin_lst)
{
	t_list *lst;
	t_list *tmp;

	if (*begin_lst && begin_lst)
	{
		lst = *begin_lst;
		while (lst)
		{
			tmp = lst->next;
			free(lst);
			lst = tmp;
		}
		*begin_lst = lst;
	}
}
