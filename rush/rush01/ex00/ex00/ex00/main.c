/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadykov <ksadykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:31:33 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/17 21:27:09 by ksadykov         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */
#include "prototypes.h"

void	desalloc(int **tab)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int argc, char **argv)
{
	int	**vert;
	int	**horiz;
	int	**board;

	if (argc != 2 || !check_inputs(argv[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	board = init_board();
	vert = init_constraint(argv[1]);
	horiz = init_constraint(argv[1] + SIZE * 2 + SIZE * 2);
	if (is_valid(vert, horiz, board, 0) && board_valid(board))
		print_board(board);
	else
		ft_putstr("Error\n");
	desalloc(board);
	desalloc(vert);
	desalloc(horiz);
	return (0);
}
