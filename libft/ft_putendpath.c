/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 19:20:47 by maxpetit          #+#    #+#             */
/*   Updated: 2016/06/24 19:21:25 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_put_endpath(char *path, char *file_name)
{
	char *tmp;

	tmp = ft_strjoin(path, "/");
	tmp = ft_strjoin_free(tmp, file_name);
	return (tmp);
}
