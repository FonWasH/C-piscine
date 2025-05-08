/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:10:51 by juperez           #+#    #+#             */
/*   Updated: 2024/02/21 17:08:15 by juperez          ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	char	*new_str;
	int		index;

	new_str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!new_str)
		return (0);
	index = 0;
	while (src[index])
	{
		new_str[index] = src[index];
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*s;
	char	*f;

	s = strdup("Test");
	f = ft_strdup("Test");
	printf("%s\n", strcmp(s, f) == 0 ? "OK" : "Fail");
	s = strdup("335456df43w35334cejr29245v2239v");
	f = ft_strdup("335456df43w35334cejr29245v2239v");
	printf("%s\n", strcmp(s, f) == 0 ? "OK" : "Fail");
	return (0);
}
*/
