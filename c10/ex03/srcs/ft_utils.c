/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:55:36 by juperez           #+#    #+#             */
/*   Updated: 2024/02/29 10:12:49 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	ft_putstr(char *str, int output)
{
	while (*str)
		write(output, str++, 1);
}

void	ft_puthex(unsigned long number, int format)
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
		ft_puthex(number / HEX, 0);
	write(1, &hex_base[number % HEX], 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	dest_size;

	dest_size = ft_strlen(dest);
	index = 0;
	while (src[index])
	{
		dest[dest_size + index] = src[index];
		index++;
	}
	dest[dest_size + index] = '\0';
	return (dest);
}
