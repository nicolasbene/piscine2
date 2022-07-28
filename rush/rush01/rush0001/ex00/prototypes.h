/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadykov <ksadykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:30:39 by ksadykov          #+#    #+#             */
/*   Updated: 2022/07/17 14:16:41 by ksadykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include <unistd.h>

int		check_inputs(char *inputs);
int		is_valid(int vert[4][2], int horiz[4][2], int board[4][4], int i);
int		board_valid(int board[4][4]);
int		absent_sur_ligne(int board[4][4], int x, int nb);
int		absent_sur_colonne(int board[4][4], int y, int nb);
int		hor_valid(int board[4][4], int horiz[4][2], int x, int i);
int		ver_valid(int board[4][4], int vert[4][2], int y, int i);
void	ft_putstr(char *str);
void	init_board(int board[4][4]);
void	init_constraints(int vert[4][2], int horiz[4][2], char *inputs);
void	print_board(int board[4][4]);
#endif
