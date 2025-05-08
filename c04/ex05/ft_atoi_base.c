/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:59:01 by juperez           #+#    #+#             */
/*   Updated: 2024/02/21 18:12:30 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_base_is_valid(char *base)
{
	int	index;
	int	search_index;

	index = 0;
	search_index = index + 1;
	while (base[index])
	{
		if ((base[index] == '-') || (base[index] == '+') || (base[index] == ' ')
			|| ((base[index] >= 9) && (base[index] <= 13)))
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

int	ft_char_in_base(char character, char *base)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (character != base[index])
			index++;
		else
			return (index);
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	index;
	int	number;
	int	negative;
	int	base_size;

	base_size = ft_base_is_valid(base);
	if (base_size <= 1)
		return (0);
	index = 0;
	number = 0;
	negative = 1;
	while ((str[index] == ' ') || ((str[index] >= 9) && (str[index] <= 13)))
		index++;
	while ((str[index] == '-') || (str[index] == '+'))
	{
		if (str[index] == '-')
			negative *= -1;
		index++;
	}
	while (ft_char_in_base(str[index], base) >= 0)
		number = number * base_size + ft_char_in_base(str[index++], base);
	return (number * negative);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("42:%d\n", ft_atoi_base("2a", "0123456789abcdef"));
	printf("-42:%d\n", ft_atoi_base("   --------+-2a", "0123456789abcdef"));
	printf("42:%d\n", ft_atoi_base("   -+-2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+- 2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-z", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", ""));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "+-0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "\t01"));
}
*/
