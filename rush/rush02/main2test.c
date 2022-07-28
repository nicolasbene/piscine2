/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:21:49 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/24 15:22:07 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_strlen(char *str)
{
        int     i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

int     ft_strlen_nbr(char *str)
{
        int     i;
        int     len;
        int     count;

        i = 0;
        count = 0;
        len = read(fd, buf, BUFFER_SIZE);     //ret = len_dico(); retour de read, trouver la ccommande 
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

//j'envoie la ligne et en parametre et renvoi le nombre a mettre dans le key_tab
int    *ft_get_nbr(char *str) //gerer comment envoyer i 
{
        int             i;
        int             j;
        int             size;
        char    **nbr;

        j = 0;
        size = ft_strlen_nbr(str);
        nbr = (char**)malloc(sizeof(char) * size + 1);
        while (j < size)
        {
                nbr[i][j] = str[j];
                j++;
        }
        return (nbr);
}


char    *ligne_get_number(char *buf, int i)
{
        char    *ligne;
        int     j;

        j = 0;

        while ()
        {
                ligne[j] = buf[i];
                i++;
                j++;
        }

}
k = get_new_ligne + 1;


int     get_next_ligne(char *str, int i)
{
        while (str[i])
        {
                if (str[i] == '\n')
                {
                        return (i);
                }
                i++;
        }
}
