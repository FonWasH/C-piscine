/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:12:18 by juperez           #+#    #+#             */
/*   Updated: 2024/02/27 18:41:20 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int ac, char *av[])
{
	int	fd;
	int	index;

	fd = 0;
	if (ac == 1)
		ft_cat(fd);
	else if (ac > 1)
	{
		index = 0;
		while (++index < ac)
		{
			fd = open(av[index], O_RDONLY);
			if (fd < 0)
				ft_error(strerror(errno), basename(av[index]));
			else
			{
				ft_cat(fd);
				close(fd);
			}
		}
	}
	return (0);
}
