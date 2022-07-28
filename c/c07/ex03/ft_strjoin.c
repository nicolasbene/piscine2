/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:01:20 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/25 21:59:27 by nibenoit         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		if (i++ != size - 1)
			len += ft_strlen(sep);
	}
	if (!size)
		len = 0;
	dest = malloc(sizeof(char) * len + 1);
	dest[0] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i++ != size - 1)
			ft_strcat(dest, sep);
	}
	ft_strcat(dest, "\0");
	return (dest);
}
