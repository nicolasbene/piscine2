/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:22:29 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/24 20:59:49 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_get_nbr(char *str)
{
	int		i;
	int		size;
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
	while (i < 1000)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	**split_dico(char *str)
{
	int		i;
	int		i2;
	int		i3;
	int		k;
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
