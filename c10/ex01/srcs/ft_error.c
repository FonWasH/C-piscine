/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:15:52 by juperez           #+#    #+#             */
/*   Updated: 2024/02/26 15:34:18 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_error(char *error, char *file)
{
	ft_putstr("ft_cat: ", 2);
	if (file)
	{
		ft_putstr(file, 2);
		ft_putstr(": ", 2);
	}
	ft_putstr(error, 2);
	ft_putstr("\n", 2);
}
