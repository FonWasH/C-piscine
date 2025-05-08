/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:24:42 by juperez           #+#    #+#             */
/*   Updated: 2024/02/15 11:32:59 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_search_str(char *str, char *to_find)
{
	int	index;

	index = 0;
	while (to_find[index])
	{
		if (str[index] == to_find[index])
			index++;
		else
			return (0);
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	index;

	if (!to_find[0])
		return (str);
	index = 0;
	while (str[index])
	{
		if (str[index] == to_find[0])
		{
			if (ft_search_str(&str[index], to_find))
				return (&str[index]);
			else
				index++;
		}
		else
			index++;
	}
	return (0);
}
