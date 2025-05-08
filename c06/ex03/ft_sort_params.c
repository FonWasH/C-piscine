/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:20:29 by juperez           #+#    #+#             */
/*   Updated: 2024/02/15 18:04:40 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] || s2[index])
	{
		if (s1[index] == s2[index])
			index++;
		else
			return (s1[index] - s2[index]);
	}
	return (0);
}

void	ft_sort_str_tab(char *argv[], int size)
{
	int		index;
	char	*temp;

	index = 0;
	while (index < (size - 1))
	{
		if (ft_strcmp(argv[index], argv[index + 1]) > 0)
		{
			temp = argv[index + 1];
			argv[index + 1] = argv[index];
			argv[index] = temp;
			index = 0;
		}
		else
		{
			index++;
		}
	}
}

int	main(int argc, char *argv[])
{
	int	index;

	if (argc >= 2)
	{
		ft_sort_str_tab(argv + 1, argc - 1);
		index = 1;
		while (index < argc)
		{
			ft_putstr(argv[index]);
			write(1, "\n", 1);
			index++;
		}
	}
	return (0);
}
