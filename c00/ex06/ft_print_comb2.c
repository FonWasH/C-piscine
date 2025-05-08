/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:31:18 by juperez           #+#    #+#             */
/*   Updated: 2024/02/07 20:15:00 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_number(int number)
{
	char	char_number;

	if (number >= 10)
	{
		char_number = '0' + (number / 10);
		write(1, &char_number, 1);
	}
	else
	{
		write(1, "0", 1);
	}
	char_number = '0' + (number % 10);
	write(1, &char_number, 1);
}

void	ft_print_comb2(void)
{
	int	number_1;
	int	number_2;

	number_1 = 0;
	number_2 = 0;
	while (number_1 < 99)
	{
		if (number_1 < number_2)
		{
			ft_print_number(number_1);
			write(1, " ", 1);
			ft_print_number(number_2);
			if (number_1 < 98)
			{
				write(1, ", ", 2);
			}
		}
		number_2++;
		if (number_2 > 99)
		{
			number_2 = 0;
			number_1++;
		}
	}
}
