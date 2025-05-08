/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:11:37 by juperez           #+#    #+#             */
/*   Updated: 2024/02/22 14:42:16 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*new_tab;
	int	index;

	if (min >= max)
		return (NULL);
	new_tab = (int *)malloc(sizeof(int) * (max - min));
	if (!new_tab)
		return (NULL);
	index = 0;
	while ((min + index) < max)
	{
		new_tab[index] = min + index;
		index++;
	}
	return (new_tab);
}

/*
#include <stdio.h>
int	main(void)
{
	int	*range;

	range = ft_range(0, 5);
	printf("0, 1, 2, 3, 4 : %d, %d, %d, %d, %d\n",
	range[0], range[1], range[2], range[3], range[4]);
	range = ft_range(-1, 1);
	printf("-1, 0 : %d, %d", range[0], range[1]);
	range = ft_range(3, 3);
}
*/
