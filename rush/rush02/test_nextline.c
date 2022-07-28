/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_nextline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:23:23 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/23 22:40:28 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *get_new_ligne(char *str)
{
        int     i;
        char    *ptr;

        i = 0;
        while (str[i])
        {
                if (str[i] == '\n')
                {
                        ptr = &str
                        return (ptr);
                }
                i++;
        }
}
int	main()
{
	char str[] = "hello \n world";
	int *res = get_new_ligne(str);

	printf("%p", res);
	return (0);
}
