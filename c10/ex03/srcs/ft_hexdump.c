/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:23:48 by juperez           #+#    #+#             */
/*   Updated: 2024/02/29 16:59:16 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

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

void	ft_print_str(t_par *par, bool is_last)
{
	if (par->option == NO_OPTION)
		ft_print_str_no_option(par, is_last);
	else if (par->option == IS_OPTION)
		ft_print_str_option(par, is_last);
}

void	ft_hexdump(int fd, t_par *par)
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
		if (par->file_count == 0)
			ft_print_str(par, false);
		read_ret = read(fd, buf, BUFFER_SIZE);
	}
	if (read_ret < 0)
		ft_error(STR_ERROR, strerror(errno), NULL);
	else if (*par->str)
	{
		par->read_count += 1;
		if ((par->file_count && par->read_count == par->file_count)
			|| (par->file_count == 0))
			ft_print_str(par, true);
	}
}
