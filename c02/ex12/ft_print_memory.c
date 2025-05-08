/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:38:06 by juperez           #+#    #+#             */
/*   Updated: 2024/02/14 16:17:44 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define HEX 16

void	ft_dec_to_hex(unsigned long number, int format)
{
	static const char	hex_base[HEX] = "0123456789abcdef";
	unsigned long		temp_number;
	int					index;

	index = 0;
	temp_number = number;
	while (++index < format)
	{
		if (temp_number < HEX)
			write(1, "0", 1);
		temp_number /= HEX;
	}
	if (number >= HEX)
		ft_dec_to_hex(number / HEX, 0);
	write(1, &hex_base[number % HEX], 1);
}

void	ft_print_data_hex(char *data, int line_size)
{
	int				index;

	index = 0;
	while (index < HEX)
	{
		if (index < line_size)
			ft_dec_to_hex((unsigned char)data[index], 2);
		else
			write(1, "  ", 2);
		if (index % 2 == 1)
			write(1, " ", 1);
		index++;
	}
}

void	ft_print_data_string(char *str, int line_size)
{
	int	index;

	index = 0;
	while (index < line_size)
	{
		if ((str[index] >= 32) && (str[index] <= 126))
			write(1, &str[index], 1);
		else
			write(1, ".", 1);
		index++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	index;
	int				line_size;

	index = 0;
	while (index * HEX < size)
	{
		line_size = size - (index * HEX);
		if (line_size >= HEX)
			line_size = HEX;
		ft_dec_to_hex((unsigned long)addr + (index * HEX), HEX);
		write(1, ": ", 2);
		ft_print_data_hex(addr + (index * HEX), line_size);
		ft_print_data_string(addr + (index * HEX), line_size);
		write(1, "\n", 1);
		index++;
	}
	return (addr);
}

/*
int	main(void)
{
	char	string[] = "Salut\n0123456789abcdef😀";
	ft_print_memory(string, 123);
}
*/
