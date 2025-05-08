/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:16:02 by juperez           #+#    #+#             */
/*   Updated: 2024/02/28 15:36:52 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

bool	ft_is_option(char *str)
{
	return (str[0] == '-');
}

bool	ft_check_option_argument(char *str, t_par *par)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (!ft_is_numeric(str[index]))
		{
			ft_error(ERROR_INVALID_ARGS, NULL, str);
			return (false);
		}
		par->bytes = (par->bytes * 10) + (str[index] - '0');
		index++;
	}
	return (true);
}

bool	ft_is_option_valid(char *av)
{
	char	option;

	if (av[1] == 'c')
		return (true);
	else
	{
		option = av[1];
		ft_error(ERROR_INVALID_OPTION, NULL, &option);
		return (false);
	}
}

void	ft_check_option(char **av, int size, t_par *par)
{
	if (av[0][2])
	{
		if (ft_check_option_argument(&av[0][2], par))
			par->option = IS_OPTION;
		else
			par->option = ERROR_OPTION;
	}
	else if (size)
	{
		if (ft_check_option_argument(av[1], par))
			par->option = IS_OPTION_NEXT;
		else
			par->option = ERROR_OPTION;
	}
	else
	{
		ft_error(ERROR_NEED_ARGS, NULL, NULL);
		par->option = ERROR_OPTION;
	}
}
