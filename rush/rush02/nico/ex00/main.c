/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:12:21 by dkeraudr          #+#    #+#             */
/*   Updated: 2022/07/24 23:17:05 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

int	check_number(char *nbr)
{
	int	index;

	index = 0;
	while (nbr[index])
	{
		if (!(nbr[index] >= '0' && nbr[index] <= '9'))
			return (0);
		index++;
	}
	if (ft_strlen(nbr) > 39)
		return (0);
	return (1);
}

int	open_file(char *str, char **values)
{
	int		fd;
	int		ret;
	char	buf[BUFFER_SIZE + 1];

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open Error\n");
		return (1);
	}
	ret = read(fd, buf, 1024);
	buf[ret] = '\0';
	values = split_dico_2(buf);
	if (close(fd) == -1)
	{
		ft_putstr("Close Error\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*strnbr;
	char	*dict_file;
	char	**values;

	values = 0;
	strnbr = 0;
	dict_file = "numbers.dict";
	if (argc == 1 || argc > 3)
		ft_putstr("Error\n");
	if (argc == 2)
	{
		strnbr = argv[1];
	}
	else if (argc == 3)
	{
		dict_file = argv[1];
		strnbr = argv[2];
	}
	if (!(check_number(strnbr)))
		ft_putstr("Error\n");
	else
	{
		open_file(dict_file, values);
		ui_to_str(strnbr, values);
	}
	return (0);
}
