/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:17:32 by juperez           #+#    #+#             */
/*   Updated: 2024/02/25 16:26:08 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	char	digit;

	if (nb >= 10)
		ft_putnbr(nb / 10);
	digit = nb % 10 + '0';
	write(1, &digit, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	index;

	index = 0;
	while (par[index].str)
	{
		ft_putstr(par[index].str);
		ft_putnbr(par[index].size);
		write(1, "\n", 1);
		ft_putstr(par[index].copy);
		index++;
	}
}
