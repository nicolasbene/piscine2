/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:32 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/17 19:22:02 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prototypes.h"

int	is_valid(int **vert, int **horiz, int **board, int i)
{
	int	x;
	int	y;
	int	nb;

	if (i == SIZE * SIZE)
		return (1);
	x = i / SIZE;
	y = i % SIZE;
	nb = 1;
	while (nb <= SIZE)
	{
		if (absent_sur_ligne(board, x, nb) && absent_sur_colonne(board, y, nb))
		{
			board[x][y] = nb;
			if (hor_valid(board, horiz, x, i) && ver_valid(board, vert, y, i))
			{
				if (is_valid(vert, horiz, board, i + 1))
					return (1);
			}
		}
		nb++;
	}
	board[x][y] = 0;
	return (0);
}
