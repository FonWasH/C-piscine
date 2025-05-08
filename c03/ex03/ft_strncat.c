/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:24:36 by juperez           #+#    #+#             */
/*   Updated: 2024/02/13 16:07:22 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	index;
	int				dest_size;

	dest_size = ft_strlen(dest);
	index = 0;
	while (src[index] && index < nb)
	{
		dest[dest_size + index] = src[index];
		index++;
	}
	dest[dest_size + index] = '\0';
	return (dest);
}
