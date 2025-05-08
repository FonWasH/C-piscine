/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:16:12 by juperez           #+#    #+#             */
/*   Updated: 2024/02/22 11:30:39 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_base_is_valid(char *base);
int	ft_char_in_base(char character, char *base);
int	ft_count_number_size(int number, int base_size, int sign);

int	ft_atoi_base(char *str, char *base, int size, int *sign)
{
	int	index;
	int	number;

	index = 0;
	number = 0;
	while ((str[index] == ' ') || ((str[index] >= 9) && (str[index] <= 13)))
		index++;
	while ((str[index] == '-') || (str[index] == '+'))
	{
		if (str[index] == '-')
			*sign *= -1;
		index++;
	}
	while (ft_char_in_base(str[index], base) >= 0)
		number = number * size + ft_char_in_base(str[index++], base);
	return (number);
}

char	*ft_putnbr_base(int number, char *base, int base_size, int sign)
{
	int		index;
	int		temp_nbr;
	char	*str;

	index = ft_count_number_size(number, base_size, sign);
	str = (char *)malloc(sizeof(char) * (index + 1));
	if (!str)
		return (0);
	str[index] = '\0';
	temp_nbr = number;
	while (index-- > 0)
	{
		if ((sign < 0) && number && !index)
			str[index] = '-';
		else
			str[index] = base[temp_nbr % base_size];
		temp_nbr /= base_size;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	base_from_size;
	int	base_to_size;
	int	number;
	int	sign;

	base_from_size = ft_base_is_valid(base_from);
	base_to_size = ft_base_is_valid(base_to);
	if ((base_from_size <= 1) || (base_to_size <= 1))
		return (0);
	sign = 1;
	number = ft_atoi_base(nbr, base_from, base_from_size, &sign);
	return (ft_putnbr_base(number, base_to, base_to_size, sign));
}

/*
#include <stdio.h>
int	main(void)
{
	printf("42:%s\n", ft_convert_base("--2a", "0123456789abcdef", "0123456789"));
	printf("-2a:%s\n", ft_convert_base("-42", "0123456789", "0123456789abcdef"));
	printf("%s\n", ft_convert_base("-0", "0123456789", "0123456789abcdef"));
}
*/
