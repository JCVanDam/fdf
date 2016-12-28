/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:09:55 by maxpetit          #+#    #+#             */
/*   Updated: 2016/07/25 18:33:14 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putstr_str_fd(const char *s1, const char *s2, const char *s3, int fd)
{
	int i;

	i = 0;
	if (s1)
		while (s1[i])
		{
			write(fd, &s1[i], 1);
			i++;
		}
	i = 0;
	if (s2)
		while (s2[i])
		{
			write(fd, &s2[i], 1);
			i++;
		}
	i = 0;
	if (s3)
		while (s3[i])
		{
			write(fd, &s3[i], 1);
			i++;
		}
}
