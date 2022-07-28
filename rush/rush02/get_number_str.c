/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:18:54 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/24 15:25:15 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_get_nbr(char *str)
{
        int             i;
        int             size;
        char    *nbr;

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

int     ft_strlen_nbr(char *str)
{
        int     i;
        int     len;
        int     count;

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

/*
char	**put_nbr_in_tab(char *nbr, int i)
{
	int	j;

	j = 0;
	while (nbr[j])
	{
		nbr_tab[i][j] = nbr[j];
		j++;
	}
	nbr[j] = 0;
	return (nbr_tab);
}
*/

char	**split_dico(char *str)
{
	int	i;
	int	k;
	int	j;
	char	*nbr_tab;
	char	**nbr_tab_main;

	i = 0;
	k = 0;
	nbr_tab_main = (char**)malloc(sizeof(char) * 41 + 1);
	while (i < 41)
	{
		//nbr_tab = malloc(sizeof(char) * ft_strlen(&str[k]) + 1);
		nbr_tab = get_number_str(&str[k]);
		j = 0;
		while (nbr_tab[j])
		{
			nbr_tab_main[i][j] = nbr_tab[j];
			j++;
		}
		nbr_tab_main[i][j] = 0;
		printf("%s\n", nbr_tab_main[i]);
		k = k + get_next_line(&str[k] + 1);
		i++;
	}
	nbr_tab_main[i] = 0;
	return (nbr_tab_main);
}
