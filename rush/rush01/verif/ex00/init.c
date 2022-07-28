/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:08:56 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/17 11:25:30 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_board(int board[4][4])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		board[i / 4][i % 4] = 0;
		i++;
	}
}

void	init_constraints(int vert[4][2], int horiz[4][2], char *inputs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 8)
	{
		if (!(inputs[i] == ' '))
		{
			vert[j % 4][j / 4] = inputs[i] - '0';
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		if (!(inputs[i] == ' '))
		{
			horiz[j % 4][j / 4] = inputs[i] - '0';
			j++;
		}
		i++;
	}
}
