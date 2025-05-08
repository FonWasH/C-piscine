/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:13:02 by juperez           #+#    #+#             */
/*   Updated: 2024/02/22 14:45:04 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*new_tab;
	int	index;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	new_tab = (int *)malloc(sizeof(int) * (max - min));
	if (!new_tab)
		return (-1);
	index = 0;
	while ((min + index) < max)
	{
		new_tab[index] = min + index;
		index++;
	}
	*range = new_tab;
	return (index);
}

/*
#include <stdio.h>
int	main(void)
{
	int	*range;

	printf("5:%d\n", ft_ultimate_range(&range, 0, 5));
	printf("0, 1, 2, 3, 4 : %d, %d, %d, %d, %d\n",
	range[0], range[1], range[2], range[3], range[4]);
	printf("0:%d\n", ft_ultimate_range(&range, 3, 3));
	printf("2:%d\n", ft_ultimate_range(&range, -1, 1));
	printf("-1, 0 : %d, %d", range[0], range[1]);
}
*/
