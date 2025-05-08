/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:15:52 by juperez           #+#    #+#             */
/*   Updated: 2024/02/28 17:09:06 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_invalid_error(char *str, char *extra)
{
	ft_putstr(str, 2);
	ft_putstr(extra, 2);
	ft_putstr("\'", 2);
}

void	ft_print_strerror(char *str, char *extra)
{
	if (extra)
	{
		ft_putstr(extra, 2);
		ft_putstr(": ", 2);
	}
	ft_putstr(str, 2);
}

void	ft_error(t_err error, char *str_error, char *extra)
{
	ft_putstr("ft_hexdump: ", 2);
	if (error == ERROR_INVALID_OPTION)
	{
		ft_print_invalid_error(INVALID_OPTION, extra);
		ft_putstr(HELP, 2);
	}
	else if ((error == STR_ERROR)
		|| (error == ERROR_INVALID_FILE))
	{
		ft_print_strerror(str_error, extra);
		if (error == ERROR_INVALID_FILE)
			ft_putstr(INVALID_FILE, 2);
	}
	ft_putstr("\n", 2);
}
