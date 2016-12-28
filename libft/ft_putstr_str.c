/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:55:32 by maxpetit          #+#    #+#             */
/*   Updated: 2016/07/25 14:54:30 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_str(char *str1, char *str2, char *str3, char *str4)
{
	if (str1)
		ft_putstr(str1);
	if (str2)
		ft_putstr(str2);
	if (str3)
		ft_putstr(str3);
	if (str4)
		ft_putstr(str4);
}
