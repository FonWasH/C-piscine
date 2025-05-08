/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:20:56 by juperez           #+#    #+#             */
/*   Updated: 2024/02/26 15:21:29 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

# define ERROR_READ_FILE "Cannot read file\n"
# define ERROR_NAME_MISSING "File name missing\n"
# define ERROR_TOO_MANY_ARGS "Too many arguments\n"

int		ft_display_file(char *path);
void	ft_error(char *error);
void	ft_putstr(char *str);

#endif
