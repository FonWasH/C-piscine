/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:50:55 by juperez           #+#    #+#             */
/*   Updated: 2024/02/29 16:37:46 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_char_hex_no_option(char *str, int size)
{
	int	index;

	index = 0;
	while (index < HEX)
	{
		if (index < size)
		{
			ft_puthex(str[index + 1], 2);
			ft_puthex(str[index], 2);
		}
		else
			ft_putstr("    ", 1);
		if (index < (HEX - 2))
			ft_putstr(" ", 1);
		index += 2;
	}
	ft_putstr("\n", 1);
}

void	ft_print_line_no_option(t_par *par, int remains_print)
{
	ft_puthex(par->total, 7);
	ft_putstr(" ", 1);
	ft_print_char_hex_no_option(&par->str[par->total], remains_print);
}

void	ft_print_str_no_option(t_par *par, bool is_last)
{
	int	remains_print;

	remains_print = ft_strlen(&par->str[par->total]);
	while (remains_print >= HEX)
	{
		ft_print_line_no_option(par, remains_print);
		par->total += HEX;
		remains_print -= HEX;
	}
	if (is_last)
	{
		if (remains_print)
		{
			ft_print_line_no_option(par, remains_print);
			par->total += remains_print;
		}
		ft_puthex(par->total, 7);
		ft_putstr("\n", 1);
	}
}
