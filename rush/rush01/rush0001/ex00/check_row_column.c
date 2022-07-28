/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_column.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:00:49 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/16 16:55:16 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	absent_sur_ligne(int board[4][4], int x, int number)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		if (board[x][j] == number)
			return (0);
		j++;
	}
	return (1);
}

int	absent_sur_colonne(int board[4][4], int y, int number)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		if (board[j][y] == number)
			return (0);
		j++;
	}
	return (1);
}
