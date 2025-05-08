/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:15:01 by juperez           #+#    #+#             */
/*   Updated: 2024/02/25 11:06:05 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

bool	ft_is_sep(char c, char *charset)
{
	int	index;

	index = 0;
	while (charset[index])
	{
		if (c == charset[index])
			return (true);
		index++;
	}
	return (false);
}

int	ft_count_string(char *str, char *charset)
{
	int		count;
	bool	can_count;

	can_count = true;
	count = 0;
	while (*str)
	{
		if (ft_is_sep(*str, charset))
			can_count = true;
		if (!ft_is_sep(*str, charset) && can_count)
		{
			can_count = false;
			count++;
		}
		str++;
	}
	return (count);
}

int	ft_string_size(char *str, char *charset)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (ft_is_sep(str[index], charset))
			return (index);
		index++;
	}
	return (index);
}

char	*ft_create_string(char *str, char *charset, int *offset)
{
	char	*new_str;
	int		str_size;
	int		index;

	str_size = ft_string_size(str, charset);
	new_str = (char *)malloc(sizeof(char) * str_size + 1);
	if (!new_str)
		return (0);
	index = 0;
	while (index < str_size)
	{
		new_str[index] = str[index];
		index++;
	}
	new_str[index] = '\0';
	*offset = str_size;
	return (new_str);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_tab;
	int		str_count;
	int		offset;
	int		index;

	str_count = ft_count_string(str, charset);
	str_tab = (char **)malloc(sizeof(char *) * (str_count + 1));
	if (!str_tab)
		return (0);
	index = 0;
	while (index < str_count)
	{		
		while (ft_is_sep(*str, charset))
			str++;
		str_tab[index] = ft_create_string(str, charset, &offset);
		if (!str_tab[index])
			return (0);
		str += offset;
		index++;
	}
	str_tab[index] = 0;
	return (str_tab);
}

/*
#include <stdio.h>
int	main(int ac, char *av[])
{
	int		index;
	char	**tab;

	if (ac == 3)
	{
		tab = ft_split(av[1], av[2]);
		index = 0;
		if (!tab)
			return (1);
		while (tab[index] != 0)
		{
			printf("%s\n", tab[index]);
			index++;
		}
	}
	return (0);
}
*/
