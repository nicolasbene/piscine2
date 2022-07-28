/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:31:33 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/17 13:28:57 by ksadykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prototypes.h"

int	main(int argc, char **argv)
{
	int	vert[4][2];
	int	horiz[4][2];
	int	board[4][4];

	if (argc != 2 || !check_inputs(argv[1]))
		ft_putstr("Error\n");
	else
	{
		init_board(board);
		init_constraints(vert, horiz, argv[1]);
		is_valid(vert, horiz, board, 0);
		if (board_valid(board))
			print_board(board);
		else
			ft_putstr("Error\n");
	}
	return (0);
}
