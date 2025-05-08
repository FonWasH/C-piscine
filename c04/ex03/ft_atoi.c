/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:58:56 by juperez           #+#    #+#             */
/*   Updated: 2024/02/20 08:46:14 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	number;
	int	negative;

	i = 0;
	number = 0;
	negative = 1;
	while ((str[i] == ' ') || ((str[i] >= 9) && (str[i] <= 13)))
			i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * negative);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("42:%d\n", ft_atoi("  \n  42t4457"));
	printf("-42:%d\n", ft_atoi(" --+-42sfs:f545"));
	printf("0:%d\n", ft_atoi("\0 1337"));
	printf("0:%d\n", ft_atoi("-0"));
	printf("0:%d\n", ft_atoi(" - 1 3 2 5 6 3 2 1 6 7"));
	printf("-1325632167:%d\n", ft_atoi("-1325632167"));
	printf("-100:%d\n", ft_atoi("-100"));
	printf("min:%d\n", ft_atoi("\t---+2147483648"));
	printf("max:%d\n", ft_atoi("\v2147483647"));
	return (0);
}
*/
