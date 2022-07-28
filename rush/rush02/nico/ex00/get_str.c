/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:24:29 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/24 23:14:08 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen_str(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != ':')
		i++;
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\n')
	{
		count++;
		i++;
	}
	return (count);
}

int	ft_beginning_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ':')
		i++;
	i++;
	while (str[i] == ' ')
		i++;
	return (i);
}

char	*ft_get_str(char *str)
{
	int		i;
	int		size;
	char	*letter;

	i = 0;
	size = ft_strlen_str(str);
	letter = malloc(size * sizeof (char) + 1);
	if (!letter)
		return (letter);
	while (i < size)
	{
		letter[i] = str[i + ft_beginning_str(str)];
		i++;
	}
	return (letter);
}

char	**split_dico_2(char *str)
{
	int		i2;
	int		i3;
	int		k;
	char	**tab2;
	char	*res;

	i2 = 0;
	k = 0;
	tab2 = (char **)malloc(sizeof(char) * 100 + 1);
	if (!tab2)
		return (0);
	while (i2 < 41)
	{
		i3 = 0;
		tab2[i2] = malloc(sizeof(char) * 100 + 1);
		while (i3 < 100)
		{
			res = ft_get_str(&str[k]);
			tab2[i2][i3] = res[i3];
			i3++;
		}
		tab2[i2][i3] = 0;
		k = k + get_next_line(&str[k]) + 1;
		i2++;
	}
	tab2[i2] = 0;
	return (tab2);
}
