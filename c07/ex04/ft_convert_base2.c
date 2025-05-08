/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:16:16 by juperez           #+#    #+#             */
/*   Updated: 2024/02/22 11:27:48 by juperez          ###   ########.fr       */
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

int	ft_count_number_size(int number, int base_size, int sign)
{
	int	number_size;

	number_size = 0;
	if (((sign < 0) && number) || (!number))
		number_size++;
	while (number > 0)
	{
		number /= base_size;
		number_size++;
	}
	return (number_size);
}
