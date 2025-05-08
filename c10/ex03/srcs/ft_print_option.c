/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:59:57 by juperez           #+#    #+#             */
/*   Updated: 2024/02/29 16:39:03 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_char_hex_option(char *str, int size)
{
	int	index;

	index = 0;
	while (index < HEX)
	{
		if (index < size)
			ft_puthex(str[index], 2);
		else
			ft_putstr("  ", 1);
		if (index < (HEX - 1))
			ft_putstr(" ", 1);
		if (index == 8)
			ft_putstr(" ", 1);
		index++;
	}
}

void	ft_print_str_ascii(char *str, int size)
{
	int	index;

	index = 0;
	ft_putstr("|", 1);
	while ((index < HEX) && (index < size))
	{
		if ((str[index] >= 32) && (str[index] <= 126))
			write(1, &str[index], 1);
		else
			write(1, ".", 1);
		index++;
	}
	ft_putstr("|", 1);
}

void	ft_print_line_option(t_par *par, int remains_print)
{
	ft_puthex(par->total, 8);
	ft_putstr("  ", 1);
	ft_print_char_hex_option(&par->str[par->total], remains_print);
	ft_putstr("  ", 1);
	ft_print_str_ascii(&par->str[par->total], remains_print);
	ft_putstr("\n", 1);
}

void	ft_print_str_option(t_par *par, bool is_last)
{
	int	remains_print;

	remains_print = ft_strlen(&par->str[par->total]);
	while (remains_print >= HEX)
	{
		ft_print_line_option(par, remains_print);
		par->total += HEX;
		remains_print -= HEX;
	}
	if (is_last)
	{
		if (remains_print)
		{
			ft_print_line_option(par, remains_print);
			par->total += remains_print;
		}
		ft_puthex(par->total, 8);
		ft_putstr("\n", 1);
	}
}
