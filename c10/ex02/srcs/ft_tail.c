/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:23:48 by juperez           #+#    #+#             */
/*   Updated: 2024/02/29 10:08:04 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_create_str(char *old, char *add)
{
	char	*new;
	int		old_size;
	int		add_size;

	old_size = ft_strlen(old);
	add_size = ft_strlen(add);
	new = (char *)malloc(sizeof(char) * (old_size + add_size + 1));
	if (!new)
		return (NULL);
	new = ft_strcat(new, old);
	new = ft_strcat(new, add);
	return (new);
}

void	ft_print_ten_lines(char *str, int size)
{
	int	index;
	int	lines_count;

	index = size;
	lines_count = 0;
	while (lines_count < 10 && (index > 0))
	{
		if (str[index] == '\n')
			lines_count++;
		if (lines_count == 10 || index == 0)
			break ;
		index--;
	}
	ft_putstr(&str[index], 1);
}

void	ft_print_tail(t_par *par)
{
	int	index;
	int	str_size;

	str_size = ft_strlen(par->str);
	if ((par->option == IS_OPTION_NEXT)
		|| (par->option == IS_OPTION))
	{
		index = 0;
		while (index < (str_size - par->bytes))
			index++;
		ft_putstr(&par->str[index], 1);
	}
	else
		ft_print_ten_lines(par->str, str_size);
}

void	ft_tail(int fd, t_par *par)
{
	int		read_ret;
	char	buf[BUFFER_SIZE];

	read_ret = read(fd, buf, BUFFER_SIZE);
	while (read_ret > 0)
	{
		buf[read_ret] = '\0';
		par->str = ft_create_str(par->str, buf);
		if (!par->str)
			return ;
		read_ret = read(fd, buf, BUFFER_SIZE);
	}
	if (read_ret < 0)
		ft_error(STR_ERROR, strerror(errno), NULL);
	else
		ft_print_tail(par);
}
