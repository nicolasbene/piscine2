/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_board_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:36:56 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/17 19:25:43 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prototypes.h"

int	board_valid(int **board)
{
	int	i;

	i = 0;
	while (i < SIZE * 4)
	{
		if (board[i / SIZE][i % SIZE] == 0)
			return (0);
		i++;
	}
	return (1);
}
