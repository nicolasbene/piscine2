/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:36:27 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/25 21:36:30 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (src == 0)
		return (0);
	while (src[i])
		i++;
	dest = malloc((i + 1) * sizeof(char));
	*dest = 0;
	if (dest == 0)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*tab_s;

	i = 0;
	tab_s = (struct s_stock_str *)malloc((ac + 1) * sizeof(struct s_stock_str));
	if (tab_s == 0)
		return (0);
	while (i < ac)
	{
		tab_s[i].size = len(av[i]);
		tab_s[i].str = (char *)malloc((sizeof(char)) * tab_s[i].size);
		*tab_s[i].str = 0;
		if (tab_s[i].str == (NULL))
			return (NULL);
		tab_s[i].str = av[i];
		tab_s[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab_s[i].str = 0;
	return (tab_s);
}
