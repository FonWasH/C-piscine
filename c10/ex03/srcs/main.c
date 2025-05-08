/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:58:46 by juperez           #+#    #+#             */
/*   Updated: 2024/02/29 15:31:34 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

bool	ft_check_main_arguments(int ac, char *av[], t_par *par)
{
	int		index;

	index = 0;
	while (index < ac)
	{
		if (ft_is_option(av[index]))
		{
			if (!ft_is_option_valid(av[index]))
				return (false);
			par->option = IS_OPTION;
		}
		else
			par->file_count += 1;
		index++;
	}
	return (true);
}

void	ft_open_files(int ac, char *av[], t_par *par)
{
	int	fd;
	int	index;

	index = 0;
	while (++index < ac)
	{
		if (!ft_is_option(av[index]))
		{
			fd = open(av[index], O_RDONLY);
			if (fd < 0)
				ft_error(ERROR_INVALID_FILE, strerror(errno), av[index]);
			else
			{
				ft_hexdump(fd, par);
				close(fd);
			}
		}
	}
}

bool	ft_init_params(t_par *par)
{
	par->file_count = 0;
	par->read_count = 0;
	par->total = 0;
	par->option = NO_OPTION;
	par->str = (char *)malloc(sizeof(char) * 1);
	if (!par->str)
		return (false);
	return (true);
}

int	main(int ac, char *av[])
{
	t_par	par;

	if (ft_init_params(&par))
	{
		if (ac == 1)
			ft_hexdump(0, &par);
		else if ((ac > 1) && ft_check_main_arguments(ac - 1, av + 1, &par))
		{	
			if (par.file_count == 0)
				ft_hexdump(0, &par);
			else
				ft_open_files(ac, av, &par);
		}
	}	
	if (par.str)
		free(par.str);
	return (0);
}
