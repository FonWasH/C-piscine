/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:07:34 by juperez           #+#    #+#             */
/*   Updated: 2024/02/29 10:12:10 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdbool.h>
# include <stdlib.h>

# define BUFFER_SIZE 30000

# define NEED_ARGS "option requires an argument -- 'c'"
# define INVALID_ARGS "invalid number of bytes: \'"
# define INVALID_OPTION "invalid option -- \'"
# define INVALID_FILE_START "cannot open '"
# define INVALID_FILE_END "' for reading: "
# define HELP "\nTry 'ft_tail --help' for more information."

typedef enum e_err
{
	ERROR_NEED_ARGS,
	ERROR_INVALID_ARGS,
	ERROR_INVALID_OPTION,
	STR_ERROR
}	t_err;

typedef enum e_opt
{
	ERROR_OPTION,
	IS_OPTION,
	IS_OPTION_NEXT,
	NO_OPTION
}	t_opt;

typedef struct s_par
{
	int		bytes;
	int		file_count;
	t_opt	option;
	char	*str;
}	t_par;

void	ft_tail(int fd, t_par *par);
void	ft_error(t_err error, char *str_error, char *extra);
bool	ft_is_option(char *str);
bool	ft_is_option_valid(char *av);
void	ft_check_option(char **av, int size, t_par *par);
int		ft_strlen(char *str);
void	ft_putstr(char *str, int output);
bool	ft_is_numeric(char c);
void	ft_print_file_name(char *str, int print_nb);
char	*ft_strcat(char *dest, char *src);

#endif
