/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:55:36 by juperez           #+#    #+#             */
/*   Updated: 2024/02/29 10:08:53 by juperez          ###   ########.fr       */
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

bool	ft_is_numeric(char c)
{
	return ((c >= '0') && (c <= '9'));
}

void	ft_print_file_name(char *str, int print_nb)
{
	if (print_nb > 1)
		ft_putstr("\n", 1);
	ft_putstr("==> ", 1);
	ft_putstr(str, 1);
	ft_putstr(" <==\n", 1);
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
