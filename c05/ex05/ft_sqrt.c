/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:19:35 by juperez           #+#    #+#             */
/*   Updated: 2024/02/20 13:43:14 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt;

	if ((nb < 0) || (nb > 2147395600))
		return (0);
	sqrt = 1;
	while ((sqrt * sqrt) < nb)
		sqrt++;
	if ((sqrt * sqrt) == nb)
		return (sqrt);
	else
		return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("10:%d\n", ft_sqrt(100));
	printf("6:%d\n", ft_sqrt(36));
	printf("0:%d\n", ft_sqrt(37));
	printf("100:%d\n", ft_sqrt(10000));
	printf("0:%d\n", ft_sqrt(10001));
	printf("2000:%d\n", ft_sqrt(4000000));
	printf("0:%d\n", ft_sqrt(-36));
	return (0);
}
*/
