/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:31:52 by dkeraudr          #+#    #+#             */
/*   Updated: 2022/07/24 22:04:18 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_from_index(int index, int space, char **values)
{
	ft_putstr(values[index]);
	if (space == 1)
		ft_putchar(' ');
	if (index > 28)
		ft_putchar(',');
}

void	dispatch_index_print(char *nbr, int tenzies, char **values)
{
	int	len;

	clean_nbr(&nbr);
	len = ft_strlen(nbr);
	if (len == 1)
		print_from_index(nbr[0] - '0', 1, values);
	else if (len == 2 && nbr[0] == '1')
		print_from_index(10 + nbr[1] - '0', 1, values);
	else if (len == 2 && nbr[0] <= '9')
	{
		if (nbr[1] != '0')
		{
			print_from_index(18 + nbr[0] - '0', 0, values);
			ft_putchar('-');
			print_from_index(nbr[1] - '0', 1, values);
		}
		else
			print_from_index(18 + nbr[0] - '0', 1, values);
	}
	else if (len == 3)
		dispatch_index_print2(nbr, values);
	if (tenzies != 0)
		print_from_index(28 + tenzies, 1, values);
}

void	dispatch_index_print2(char *nbr, char **values)
{
	print_from_index(nbr[0] - '0', 1, values);
	print_from_index(28, 1, values);
	nb_shift(&nbr);
	dispatch_index_print(nbr, 0, values);
}

void	ui_to_str(char *nbr, char **values)
{
	int		len;
	int		max;
	char	tri[4];
	int		index;

	index = -1;
	len = ft_strlen(nbr);
	max = 3;
	if (len % 3 != 0)
		max = len % 3;
	if (len == 0)
		return ;
	if (len <= 3)
		dispatch_index_print(nbr, 0, values);
	else if (len > 3)
	{
		while (index++ < max)
		{
			tri[index] = nbr[0];
			tri[index + 1] = '\0';
			nb_shift(&nbr);
		}
		dispatch_index_print(tri, (len - 1) / 3, values);
		ui_to_str(nbr, values);
	}
}
