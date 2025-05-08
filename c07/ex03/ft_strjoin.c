/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:13:41 by juperez           #+#    #+#             */
/*   Updated: 2024/02/22 12:17:36 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	return (index);
}

int	ft_count_str_size(int size, char **strs, char *sep)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < size)
	{
		count += (ft_strlen(strs[index]));
		if (index < (size - 1))
			count += ft_strlen(sep);
		index++;
	}
	return (count);
}

char	*ft_create_str(int size, char **strs, char *sep, char *str)
{
	int	index;
	int	offset;

	index = 0;
	offset = 0;
	while (index < size)
	{
		offset += ft_strcpy(&str[offset], strs[index]);
		if (index < (size - 1))
			offset += ft_strcpy(&str[offset], sep);
		index++;
	}
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*new_str;
	int		str_size;

	if (!sep)
		sep = "";
	str_size = ft_count_str_size(size, strs, sep);
	new_str = (char *)malloc(sizeof(char) * (str_size + 1));
	if (!new_str)
		return (0);
	new_str = ft_create_str(size, strs, sep, new_str);
	new_str[str_size] = '\0';
	return (new_str);
}

/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc)
		printf("%s", ft_strjoin(argc, argv, "/"));
	return (0);
}
*/
