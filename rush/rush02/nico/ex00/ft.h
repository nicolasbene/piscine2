/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:21:25 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/24 22:03:41 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
int		ft_strlen_nbr(char *str);
char	*ft_get_nbr(char *str);
int		get_next_line(char *str);
char	**split_dico(char *str);
void	print_from_index(int index, int space, char **values);
void	dispatch_index_print(char *nbr, int tenzies, char **values);
void	dispatch_index_print2(char *nbr, char **values);
void	ui_to_str(char *nbr, char **values);
int		ft_strlen_nbr(char *str);
char	*ft_get_nbr(char *str);
int		get_next_line(char *str);
char	**split_dico(char *str);
int		ft_strlen_str(char *str);
int		ft_beginning_str(char *str);
char	*ft_get_str(char *str);
char	**split_dico_2(char *str);
void    clean_nbr(char **nbr);
int     nb_shift(char **nbr);
#endif
