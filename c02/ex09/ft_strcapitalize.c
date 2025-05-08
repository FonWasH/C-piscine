/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:37:49 by juperez           #+#    #+#             */
/*   Updated: 2024/02/11 19:25:21 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LOWER 1
#define UPPER 2
#define NUM 3

int	ft_check(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (LOWER);
	else if ((c >= 'A') && (c <= 'Z'))
		return (UPPER);
	else if ((c >= '0') && (c <= '9'))
		return (NUM);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
		{
			if (ft_check(str[i]) == LOWER)
				str[i] -= 32;
		}
		else
		{
			if ((ft_check(str[i]) == LOWER) && !(ft_check(str[i - 1])))
				str[i] -= 32;
			else if ((ft_check(str[i]) == UPPER) && (ft_check(str[i - 1])))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}

/*
#include <stdio.h>
int main(void)
{
	char string[] = "salut, comment tu vas ? 42mots quaRante-deux; cinquante+et+un";
	printf("%s", ft_strcapitalize(string));
}\
*/
