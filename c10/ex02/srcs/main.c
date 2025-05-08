/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:58:46 by juperez           #+#    #+#             */
/*   Updated: 2024/02/29 15:31:50 by juperez          ###   ########.fr       */
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
			ft_check_option(&av[index], (ac - 1) - index, par);
			if (par->option == ERROR_OPTION)
				return (false);
			if (par->option == IS_OPTION_NEXT)
				index++;
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
	int	print_nb;

	index = 0;
	print_nb = 0;
	while (++index < ac)
	{
		if (ft_is_option(av[index]) && par->option == IS_OPTION_NEXT)
			index++;
		else if (!ft_is_option(av[index]))
		{
			fd = open(av[index], O_RDONLY);
			if (fd < 0)
				ft_error(STR_ERROR, strerror(errno), av[index]);
			else
			{
				if (par->file_count > 1)
					ft_print_file_name(av[index], ++print_nb);
				ft_tail(fd, par);
				close(fd);
			}
		}
	}
}

bool	ft_init_params(t_par *par)
{
	par->bytes = 0;
	par->file_count = 0;
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
			ft_tail(0, &par);
		else if ((ac > 1) && ft_check_main_arguments(ac - 1, av + 1, &par))
		{	
			if (par.file_count == 0)
				ft_tail(0, &par);
			else
				ft_open_files(ac, av, &par);
		}
	}
	if (par.str)
		free(par.str);
	return (0);
}
