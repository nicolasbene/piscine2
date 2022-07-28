/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:46:38 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/25 18:53:53 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*ret;
	int	i;

	if (min >= max)
		return (0);
	ret = malloc((max - min) * sizeof(int));
	if (!ret)
		return (0);
	i = 0;
	while (i < max - min)
	{
		ret[i] = min + i;
		i++;
	}
	return (ret);
}
