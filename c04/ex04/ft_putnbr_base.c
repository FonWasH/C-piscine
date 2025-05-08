/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:58:58 by juperez           #+#    #+#             */
/*   Updated: 2024/02/21 09:50:19 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_base_is_valid(char *base)
{
	unsigned int	index;
	unsigned int	search_index;

	index = 0;
	search_index = index + 1;
	while (base[index])
	{
		if ((base[index] == '-') || (base[index] == '+'))
			return (0);
		while (base[search_index])
		{
			if (base[index] != base[search_index])
				search_index++;
			else
				return (0);
		}
		index++;
		search_index = index + 1;
	}
	return (index);
}

void	ft_convert_to_base(unsigned int number, char *base, unsigned int size)
{
	if (number >= size)
		ft_convert_to_base(number / size, base, size);
	write(1, &base[number % size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	number;
	unsigned int	base_size;

	base_size = ft_base_is_valid(base);
	if (base_size > 1)
	{
		if (nbr < 0)
		{
			number = -nbr;
			write(1, "-", 1);
		}
		else
			number = nbr;
		ft_convert_to_base(number, base, base_size);
	}
}

/*
int	main(void)
{
	write(1, "42:", 3);
	ft_putnbr_base(42, "0123456789");
	write(1, "\n2a:", 4);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n-2a:", 5);
	ft_putnbr_base(-42, "0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "");
	write(1, "\n:", 2);
	ft_putnbr_base(-42, "001");
	write(1, "\n:", 2);
	ft_putnbr_base(-42, "01");
	write(1, "-101010:", 2);
	return (0);
}
*/
