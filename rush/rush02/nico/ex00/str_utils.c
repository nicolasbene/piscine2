/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:37:25 by dkeraudr          #+#    #+#             */
/*   Updated: 2022/07/24 22:05:11 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	nb_shift(char **nbr)
{
	int	index;

	index = 0;
	while (nbr[0][index])
	{
		nbr[0][index] = nbr[0][index + 1];
		index++;
	}
}

void	clean_nbr(char **nbr)
{
	while (nbr[0][0] == '0')
		nb_shift(nbr);
}
