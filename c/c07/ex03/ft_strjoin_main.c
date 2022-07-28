/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:36:21 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/20 11:00:30 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_alloc_size(char **strs, char *sep, int size)
{
	int	i;
	int	resultat;
	
	i = 0;
	
	while (i < size)
	{
		resultat += ft_strlen(strs[i]);
		i++;
	}
	resultat += ft_strlen(sep) * (size - 1); 
	return (resultat + 1);
}


char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len_dest;

	i = 0;
	len_dest = ft_strlen(dest);
	while (src[i])
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = 0;
	return (dest);

}


char *ft_strjoin(int size, char **strs, char *sep)
{
	char	*resultat;
	int		i;

	resultat = malloc(sizeof(char) * get_alloc_size(strs, sep, size));
	if (!resultat)
		return (0);
	resultat[0] = 0;
	if (size == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		ft_strcat(resultat, strs[i]);
		if (i != size - 1)
			ft_strcat(resultat, sep);
		i++;
	}
	resultat[ft_strlen(resultat)] = 0;
	return (resultat);

}
int	main(void)
{
	int		index;
	char	**strs;
	char	*separator;
	char	*result;
	int	size;

	size = 3;
	strs = (char **)malloc(3 * sizeof(char *));
	strs[0] = (char *)malloc(sizeof(char) * 5 + 1);
	strs[1] = (char *)malloc(sizeof(char) * 7 + 1);
	strs[2] = (char *)malloc(sizeof(char) * 14 + 1);
	strs[0] = "Hello";
	strs[1] = "friend,";
	strs[2] = "you are awesome";
	separator = " ";
	result = ft_strjoin(size, strs, separator);
	printf("%s$\n", result);
	free(result);
}
