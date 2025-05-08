/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:20:47 by juperez           #+#    #+#             */
/*   Updated: 2024/02/20 18:23:14 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define TRUE 1
#define FALSE 0

void	ft_print_board(int board[10][10])
{
	int		x;
	int		y;
	char	digit;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			if (board[y][x])
			{
				digit = y + '0';
				write(1, &digit, 1);
			}
			y++;
		}
		x++;
	}
	write(1, "\n", 1);
}

int	ft_can_place_queen(int board[10][10], int x, int y)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (board[y][i] || board[i][x]
			|| ((y + i < 10) && (x - i >= 0) && (board[y + i][x - i]))
			|| ((y - i >= 0) && (x + i < 10) && (board[y - i][x + i]))
			|| ((y - i >= 0) && (x - i >= 0) && (board[y - i][x - i]))
			|| ((y + i < 10) && (x + i < 10) && (board[y + i][x + i])))
			return (FALSE);
		else
			i++;
	}
	return (TRUE);
}

void	ft_resolve_puzzle(int board[10][10], int x, int *results)
{
	int	y;

	if (x >= 10)
	{
		*results = *results + 1;
		ft_print_board(board);
	}
	else
	{
		y = 0;
		while (y < 10)
		{
			if (ft_can_place_queen(board, x, y))
			{
				board[y][x] = 1;
				ft_resolve_puzzle(board, x + 1, results);
				board[y][x] = 0;
			}
			y++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10][10];
	int	results;
	int	x;
	int	y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			board[y][x] = 0;
			x++;
		}
		y++;
	}
	results = 0;
	ft_resolve_puzzle(board, 0, &results);
	return (results);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("\n%d solutions\n", ft_ten_queens_puzzle());
	return (0);
}
*/
