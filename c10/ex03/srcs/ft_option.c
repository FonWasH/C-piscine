/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:16:02 by juperez           #+#    #+#             */
/*   Updated: 2024/02/28 17:09:55 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

bool	ft_is_option(char *str)
{
	return (str[0] == '-');
}

bool	ft_is_option_valid(char *av)
{
	char	option;

	if ((av[1] == 'C') && (av[2] == '\0'))
		return (true);
	else if (av[1] != 'C')
	{
		option = av[1];
		ft_error(ERROR_INVALID_OPTION, NULL, &option);
	}
	else if (av[2])
	{
		option = av[2];
		ft_error(ERROR_INVALID_OPTION, NULL, &option);
	}
	return (false);
}
