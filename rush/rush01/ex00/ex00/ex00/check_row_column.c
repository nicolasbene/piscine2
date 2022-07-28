/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_column.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:00:49 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/17 17:40:55 by ksadykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prototypes.h"

int	absent_sur_ligne(int **board, int x, int number)
{
	int	j;

	j = 0;
	while (j < SIZE)
	{
		if (board[x][j] == number)
			return (0);
		j++;
	}
	return (1);
}

int	absent_sur_colonne(int **board, int y, int number)
{
	int	j;

	j = 0;
	while (j < SIZE)
	{
		if (board[j][y] == number)
			return (0);
		j++;
	}
	return (1);
}
