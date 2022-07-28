/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadykov <ksadykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:08:56 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/17 21:28:18 by ksadykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prototypes.h"

int	**init_board(void)
{
	int	**board;
	int	i;

	board = (int **) malloc(sizeof(int *) * SIZE);
	i = 0;
	while (i < SIZE)
	{
		board[i] = (int *) malloc(sizeof(int) * SIZE);
		i++;
	}
	i = 0;
	while (i < SIZE * 4)
	{
		board[i / SIZE][i % SIZE] = 0;
		i++;
	}
	return (board);
}

int	**init_constraint(char *inputs)
{
	int	i;
	int	j;
	int	**tab;

	i = 0;
	j = 0;
	tab = (int **) malloc(sizeof(int *) * SIZE);
	while (i < SIZE)
	{
		tab[i] = (int *) malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (j < SIZE * 2)
	{
		if (!(inputs[i] == ' '))
		{
			tab[j % SIZE][j / SIZE] = inputs[i] - '0';
			j++;
		}
		i++;
	}
	return (tab);
}
