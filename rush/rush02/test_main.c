/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:23:59 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/23 16:25:07 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "ft_dict.h"

int		main(int argc, char **argv)
{
	t_list	*dict;
	char	*path;
	char	*value;
	char	*content;

	ft_check_args(argc, argv, &path, &value);
	if (!ft_is_valid(value))
		ft_putstr("Error\n");
	else if ((content = ft_file_load(path)))
	{
		dict = ft_dict_create(content);
		free(content);
		if (dict)
		{
			ft_print(dict, value);
			ft_list_clear(dict, &ft_dict_clear);
		}
	}
	else
		ft_putstr("Dict Error\n");
	return (0);
}

#include <stdlib.h>

void	ft_check_args(int argc, char **argv, char **path, char **value)
{
	if (argc < 2 || argc > 3)
	{
		*path = NULL;
		*value = NULL;
	}
	if (argc == 2)
	{
		*path = "numbers.dict";
		*value = argv[1];
	}
	else
	{
		*path = argv[1];
		*value = argv[2];
	}
}
