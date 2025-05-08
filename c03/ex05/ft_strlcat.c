/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:24:46 by juperez           #+#    #+#             */
/*   Updated: 2024/02/19 11:33:54 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dest_size;
	unsigned int	src_size;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (!size || size <= dest_size)
		return (size + src_size);
	index = 0;
	while (src[index] && (index < (size - dest_size - 1)))
	{
		dest[dest_size + index] = src[index];
		index++;
	}
	dest[dest_size + index] = '\0';
	return (dest_size + src_size);
}
