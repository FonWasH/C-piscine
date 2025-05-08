/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:58:52 by juperez           #+#    #+#             */
/*   Updated: 2024/02/20 08:44:54 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_number(unsigned int number)
{
	char	digit;

	if (number >= 10)
		ft_print_number(number / 10);
	digit = (number % 10) + '0';
	write(1, &digit, 1);
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
		number = nb;
	ft_print_number(number);
}

/*
#include <stdio.h>
int	main(void)
{
	ft_putnbr(42);
	printf("\n");
	ft_putnbr(-42);
	printf("\n");
	ft_putnbr(-2147483648);
	printf("\n");
	ft_putnbr(2147483647);
	printf("\n");
	return (0);
}
*/
