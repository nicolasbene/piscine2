/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:57:09 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/17 19:05:37 by ksadykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prototypes.h"

int	check_inputs(char *inputs)
{
	int	i;

	i = 0;
	while (inputs[i])
	{
		if (!(inputs[i] == ' ' || (inputs[i] >= '1' && inputs[i] <= SIZE + 48)))
			return (0);
		else if ((i % 2 == 0) && inputs[i] == ' ')
			return (0);
		i++;
	}
	if (i != SIZE * 4 + SIZE * 4 - 1)
		return (0);
	return (1);
}
