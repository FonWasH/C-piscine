/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:23:48 by juperez           #+#    #+#             */
/*   Updated: 2024/02/28 13:58:45 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_cat(int fd)
{
	int		ret;
	char	buf[BUFFER_SIZE];

	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		ft_putstr(buf, 1);
		ret = read(fd, buf, BUFFER_SIZE);
	}
	if (ret < 0)
	{
		ft_error(strerror(errno), NULL);
		return ;
	}
}
