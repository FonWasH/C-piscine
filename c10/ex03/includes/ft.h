/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:07:34 by juperez           #+#    #+#             */
/*   Updated: 2024/02/29 16:00:20 by juperez          ###   ########.fr       */
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
# define HEX 16

# define INVALID_OPTION "invalid option -- \'"
# define INVALID_FILE "\nft_hexdump: all input file arguments failed"
# define HELP "\nTry 'ft_hexdump --help' for more information."

typedef enum e_err
{
	ERROR_INVALID_OPTION,
	ERROR_INVALID_FILE,
	STR_ERROR
}	t_err;

typedef enum e_opt
{
	IS_OPTION,
	NO_OPTION
}	t_opt;

typedef struct s_par
{
	int		file_count;
	int		read_count;
	int		total;
	t_opt	option;
	char	*str;
}	t_par;

void	ft_hexdump(int fd, t_par *par);
void	ft_print_str_no_option(t_par *par, bool is_last);
void	ft_print_str_option(t_par *par, bool is_last);
void	ft_error(t_err error, char *str_error, char *extra);
bool	ft_is_option(char *str);
bool	ft_is_option_valid(char *av);
void	ft_check_option(char **av, int size, t_par *par);
int		ft_strlen(char *str);
void	ft_putstr(char *str, int output);
void	ft_puthex(unsigned long number, int format);
char	*ft_strcat(char *dest, char *src);

#endif
