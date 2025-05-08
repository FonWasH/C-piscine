/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:20:25 by juperez           #+#    #+#             */
/*   Updated: 2024/02/15 17:40:47 by juperez          ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		while (argc > 1)
		{
			ft_putstr(argv[argc - 1]);
			write(1, "\n", 1);
			argc--;
		}
	}
	return (0);
}
