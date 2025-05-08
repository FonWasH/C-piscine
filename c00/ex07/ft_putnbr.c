/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:47:12 by juperez           #+#    #+#             */
/*   Updated: 2024/02/09 09:00:54 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printnbr(unsigned int number)
{
	char	char_number;

	char_number = (number % 10) + '0';
	if (number >= 10)
	{
		ft_printnbr(number / 10);
	}
	write(1, &char_number, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	number;

	if (nb < 0)
	{
		write(1, "-", 1);
		number = -nb;
	}
	else
	{
		number = nb;
	}
	ft_printnbr(number);
}
