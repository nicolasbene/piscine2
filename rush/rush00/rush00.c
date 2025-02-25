/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 10:09:26 by nwyseur           #+#    #+#             */
/*   Updated: 2022/07/09 14:34:02 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print(int x, int y, int ligne, int colonne)
{
	if ((ligne == 1 && colonne == 1) || (ligne == y && colonne == 1))
		ft_putchar('o');
	else if ((ligne == 1 && colonne == x) || (ligne == y && colonne == x))
		ft_putchar('o');
	else if (ligne == 1 && (colonne > 1 && colonne < x))
		ft_putchar('-');
	else if ((ligne > 1 && ligne < y) && (colonne == 1))
		ft_putchar('|');
	else if ((ligne > 1 && ligne < y) && colonne == x)
		ft_putchar('|');
	else if (ligne == y && (colonne > 1 && colonne < x))
		ft_putchar('-');
	else if ((ligne > 1 && ligne < y) && (colonne > 1 && colonne < x))
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	ligne;
	int	colonne;

	ligne = 1;
	if (!(x <= 0 || y <= 0))
	{		
		while (ligne <= y)
		{
			colonne = 1;
			while (colonne <= x)
			{
				ft_print(x, y, ligne, colonne);
				colonne++;
			}
			ft_putchar('\n');
			ligne++;
		}
	}
}
