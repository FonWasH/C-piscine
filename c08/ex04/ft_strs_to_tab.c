/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:17:26 by juperez           #+#    #+#             */
/*   Updated: 2024/02/25 16:48:12 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strdup(char *str)
{
	int		index;
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!new_str)
		return (NULL);
	index = 0;
	while (str[index])
	{
		new_str[index] = str[index];
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*tab;
	int					index;

	tab = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	index = 0;
	while (index < ac)
	{
		tab[index].size = ft_strlen(av[index]);
		tab[index].str = ft_strdup(av[index]);
		if (!tab[index].str)
			return (NULL);
		tab[index].copy = ft_strdup(av[index]);
		if (!tab[index].copy)
			return (NULL);
		index++;
	}
	tab[index].str = 0;
	return (tab);
}

/*
int	main(int argc, char *argv[])
{
	struct s_stock_str	*stock;

	if (argc)
	{
		stock = ft_strs_to_tab(argc, argv);
		ft_show_tab(stock);
	}
	return (0);
}
*/
