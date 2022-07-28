/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadykov <ksadykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:30:39 by ksadykov          #+#    #+#             */
/*   Updated: 2022/07/17 21:25:25 by ksadykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# define SIZE 4
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		check_inputs(char *inputs);
int		is_valid(int **vert, int **horiz, int **board, int i);
int		board_valid(int **board);
int		absent_sur_ligne(int **board, int x, int nb);
int		absent_sur_colonne(int **board, int y, int nb);
int		hor_valid(int **board, int **horiz, int x, int i);
int		ver_valid(int **board, int **vert, int y, int i);
void	ft_putstr(char *str);
int		**init_board(void);
int		**init_constraint(char *inputs);
void	print_board(int **board);
#endif
