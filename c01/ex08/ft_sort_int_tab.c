/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:32:17 by juperez           #+#    #+#             */
/*   Updated: 2024/02/08 20:45:08 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	index;

	index = 0;
	while (index < (size - 1))
	{
		if (tab[index] > tab[index + 1])
		{
			temp = tab[index + 1];
			tab[index + 1] = tab[index];
			tab[index] = temp;
			index = 0;
		}
		else
		{
			index++;
		}
	}
}
