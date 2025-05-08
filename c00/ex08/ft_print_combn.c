/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:22:00 by juperez           #+#    #+#             */
/*   Updated: 2024/02/14 18:23:45 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(int *tab, int size)
{
	int		index;
	char	digit;

	index = 0;
	while (index < size)
	{
		digit = tab[index] + '0';
		write(1, &digit, 1);
		index++;
	}
	if (!((tab[0] + size) == 10))
	{
		write(1, ", ", 2);
	}
}

void	ft_is_printable(int *tab, int current, int size)
{
	if (current == 0)
	{
		ft_print_comb(tab, size);
	}
	else if ((current > 0) && (tab[current] > tab[current - 1]))
	{
		ft_is_printable(tab, current - 1, size);
	}
}

void	ft_check_count(int *tab, int index)
{
	while (index > 0)
	{
		if (tab[index] > 9 && index > 0)
		{
			tab[index] = 0;
			tab[index - 1]++;
		}
		index--;
	}
}

void	ft_count_tab(int *tab, int last, int size)
{
	while (tab[0] < 10) // || ((size == 9) && (tab[0] < MAX)))
	{
		ft_check_count(tab, last);
		ft_is_printable(tab, last, size);
		tab[last]++;
	}
}

void	ft_print_combn(int n)
{
	int	tab[9];
	int	index;

	if (n > 0 && n < 10)
	{
		index = 0;
		while (index < 9)
		{
			tab[index] = 0;
			index++;
		}	
		ft_count_tab(tab, n - 1, n);
	}
}
