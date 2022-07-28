/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:50:32 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/17 13:52:49 by ksadykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prototypes.h"

int	is_valid(int vert[4][2], int horiz[4][2], int board[4][4], int i)
{
	int	x;
	int	y;
	int	nb;

	if (i == 16)
		return (1);
	x = i / 4;
	y = i % 4;
	nb = 1;
	while (nb <= 4)
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
