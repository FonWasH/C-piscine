/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:38:01 by juperez           #+#    #+#             */
/*   Updated: 2024/02/15 10:36:45 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define HEX 16

void	ft_char_to_hex(unsigned char character, int format)
{
	static const char	hex_base[HEX] = "0123456789abcdef";
	unsigned char		temp_character;
	int					index;

	index = 0;
	temp_character = character;
	while (++index < format)
	{
		if (temp_character < HEX)
			write(1, "0", 1);
		temp_character /= HEX;
	}
	if (character >= HEX)
		ft_char_to_hex((character / HEX), 0);
	write(1, &hex_base[character % HEX], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				index;

	index = 0;
	while (str[index])
	{
		if ((str[index] >= 32) && (str[index] <= 126))
			write(1, &str[index], 1);
		else
		{
			write(1, "\\", 1);
			ft_char_to_hex((unsigned char)str[index], 2);
		}
		index++;
	}
}

/*
int	main(void)
{
	char	string[] = "Coucou\ntu vas bien ?\r\f\n\t\v\r";
	ft_putstr_non_printable(string);
}
*/
