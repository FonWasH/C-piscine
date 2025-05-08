/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:07:34 by juperez           #+#    #+#             */
/*   Updated: 2024/02/26 15:38:12 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>

# define BUFFER_SIZE 30000

void	ft_cat(int fd);
void	ft_error(char *error, char *file);
void	ft_putstr(char *str, int output);

#endif
