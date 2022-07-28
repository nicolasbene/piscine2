/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_constraints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadykov <ksadykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:59:36 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/17 21:28:21 by ksadykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prototypes.h"

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		ri;
	int		swap;

	i = 0;
	ri = size - 1;
	while (i < (size / 2))
	{
		swap = tab[i];
		tab[i] = tab[ri];
		tab[ri] = swap;
		i++;
		ri--;
	}
}

int	compteur_vues(int *tab)
{
	int	i;
	int	count;
	int	curr_max;

	i = 0;
	count = 0;
	curr_max = 0;
	while (i < SIZE)
	{
		if (tab[i] > curr_max)
		{
			count++;
			curr_max = tab[i];
		}
		i++;
	}
	return (count);
}

int	*init_nbrs(int **board, int xy, int choice)
{
	int	*nbrs;
	int	j;

	j = 0;
	nbrs = (int *) malloc(sizeof(int) * SIZE);
	if (choice == 1)
	{
		while (j < SIZE)
		{
			nbrs[j] = board[xy][j];
			j++;
		}
	}
	else
	{
		while (j < SIZE)
		{
			nbrs[j] = board[j][xy];
			j++;
		}
	}
	return (nbrs);
}

int	hor_valid(int **board, int **horiz, int x, int i)
{
	int	vues;
	int	*nbrs;

	nbrs = init_nbrs(board, x, 1);
	if ((i + 1) % SIZE == 0)
	{
		vues = compteur_vues(nbrs);
		if (horiz[x][0] == vues)
		{
			ft_rev_int_tab(nbrs, SIZE);
			vues = compteur_vues(nbrs);
			if (horiz[x][1] == vues)
			{
				free(nbrs);
				return (1);
			}
		}
		free(nbrs);
		return (0);
	}
	free(nbrs);
	return (1);
}

int	ver_valid(int **board, int **vert, int y, int i)
{
	int	vues;
	int	*nbrs;

	nbrs = init_nbrs(board, y, 2);
	if (i >= SIZE * SIZE - SIZE && i < SIZE * SIZE)
	{
		vues = compteur_vues(nbrs);
		if (vert[y][0] == vues)
		{
			ft_rev_int_tab(nbrs, SIZE);
			vues = compteur_vues(nbrs);
			if (vert[y][1] == vues)
			{
				free(nbrs);
				return (1);
			}
		}
		free(nbrs);
		return (0);
	}
	free(nbrs);
	return (1);
}
