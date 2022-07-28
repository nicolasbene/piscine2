/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_constraints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:59:36 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/17 13:54:32 by ksadykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	compteur_vues(int tab[4])
{
	int	i;
	int	count;
	int	curr_max;

	i = 0;
	count = 0;
	curr_max = 0;
	while (i < 4)
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

int	hor_valid(int board[4][4], int horiz[4][2], int x, int i)
{
	int	vues;
	int	nbrs[4];

	nbrs[0] = board[x][0];
	nbrs[1] = board[x][1];
	nbrs[2] = board[x][2];
	nbrs[3] = board[x][3];
	if (i == 3 || i == 7 || i == 11 || i == 15)
	{
		vues = compteur_vues(nbrs);
		if (horiz[x][0] == vues)
		{
			ft_rev_int_tab(nbrs, 4);
			vues = compteur_vues(nbrs);
			if (horiz[x][1] == vues)
				return (1);
		}
		return (0);
	}
	else
		return (1);
}

int	ver_valid(int board[4][4], int vert[4][2], int y, int i)
{
	int	vues;
	int	nbrs[4];

	nbrs[0] = board[0][y];
	nbrs[1] = board[1][y];
	nbrs[2] = board[2][y];
	nbrs[3] = board[3][y];
	if (i >= 12 && i <= 15)
	{
		vues = compteur_vues(nbrs);
		if (vert[y][0] == vues)
		{
			ft_rev_int_tab(nbrs, 4);
			vues = compteur_vues(nbrs);
			if (vert[y][1] == vues)
				return (1);
		}
		return (0);
	}
	else
		return (1);
}
