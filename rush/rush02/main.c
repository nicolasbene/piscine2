/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:21:08 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/24 22:24:41 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>
#define BUFFER_SIZE 1024

char	*ft_get_nbr(char *str)
{
        int	i;
        int	size;
        char	*nbr;

	i = 0;
	size = ft_strlen_nbr(str);
        nbr = malloc(sizeof(char) * size + 1);
	while (i < size)
	{
		nbr[i] = str[i];
		i++;
	}
	nbr[i] = '\0';
	return (nbr);
}

int	ft_strlen_nbr(char *str)
{
	int	i;
	int	len;
	int	count;

	i = 0;
	count = 0;
	len = 100;
	while (i < len)
	{
		if (str[i] == ' ')
			return (count);
		if (str[i] >= '0' && str[i] <= '9')
			count++;
		i++;
	}
	return (count);
}

int	get_next_line(char *str)
{
	int	i;

	i = 0;
	while(i < 1000)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	**split_dico(char *str)
{	
	int	i;
	int	i2;
	int	i3;
	int	k;
	char	**tab;
	char	**tab2;
	char	*nbr;

	i = 0;
	i2 = 0;
	k = 0;
	tab = (char**)malloc(sizeof(char) * 41 + 1);
	if (!tab)
		return (0);
	while (i2 < 41)
	{
		i3 = 0;
		tab[i2] = malloc(sizeof(char) * 128 + 1);
		while (i3 < 100)
			{
				nbr = ft_get_nbr(&str[k]);
				tab[i2][i3] = nbr[i3];
				i3++;
			}
		tab[i2][i3] = 0;
		printf("%s\n", tab[i2]);
		k = k + get_next_line(&str[k]) + 1;
		i2++;
	}
	tab[i2] = 0;
	return (tab);
}

int     ft_strlen_str(char *str)
{
	int     i;
	int     count;

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


char    *ft_get_str(char *str)
{
	int	i;
	int	size;
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

char    **split_dico_2(char *str)
{
	int	i2;
	int	i3;
	int	k;
	char	**tab2;
	char	*res;

	i2 = 0;
	k = 0;
	tab2 = (char**)malloc(sizeof(char) * 41 + 1);
	if (!tab2)
		return (0);
	while (i2 < 41)
	{
		i3 = 0;
		tab2[i2] = malloc(sizeof(char) * 11 + 1);
		while (i3 < 11)
			{
				res = ft_get_str(&str[k]);
				tab2[i2][i3] = res[i3];
				i3++;
			}
		tab2[i2][i3] = 0;
		printf("%s\n", tab2[i2]);
		k = k + get_next_line(&str[k]) + 1;
		i2++;
	}
	tab2[i2] = 0;
	return (tab2);
}

int	main(int argc, char **argv)
{
	char	*strnbr;
	int	fd;
	int	ret;
	char	buf[BUFFER_SIZE + 1];
	char	c;
	int	len_dict;

	fd = 0;
	ret = 0;
	if (argc == 2)
	{
		fd = open("numbers.dict", O_RDONLY);
	}
	/*	else if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		printf("%d", fd);
	}
	*/
	if (fd == -1)
	{
		ft_putstr("Open Error\n");
		return (1);
	}

	while (ret = read(fd, buf, 1000))
	{
		buf[ret] = '\0';
		ft_putnbr(ret);
		len_dict = ret;
	//		ft_putstr(buf);
	}
	ft_putnbr(ret);
	ft_putchar('\n');

//	split_dico(buf);
	split_dico_2(buf);	

	if (close(fd) == -1)
	{
		ft_putstr("Close Error\n");
		return (1);
	}
	return (0);
}
