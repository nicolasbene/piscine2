/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:06:56 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/19 19:46:04 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*tab;
	int		size;
	int		i;

	size = ft_strlen(src);
	tab = malloc(sizeof(int) * size + 1);
	if (!tab)
		return (0);
	i = 0;
	while (i < size)
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}
