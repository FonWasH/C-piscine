/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:08:08 by juperez           #+#    #+#             */
/*   Updated: 2024/02/08 17:47:08 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_number(char *number)
{
	if (number[0] < number[1] && number[1] < number[2])
	{
		write(1, number, 3);
		if (number[0] <= '6')
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	char	number[3];

	number[0] = '0';
	number[1] = '0';
	number[2] = '0';
	while (number[0] < '9')
	{
		ft_print_number(number);
		number[2]++;
		if (number[2] > '9')
		{
			number[2] = '0';
			number[1]++;
		}
		if (number[1] > '9')
		{
			number[1] = '0';
			number[0]++;
		}
	}
}
