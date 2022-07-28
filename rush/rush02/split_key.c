/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:40:52 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/23 21:40:56 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     *split_key(char *str) 
{ 
        int     i; 
        int     j; 
        int     result; 
        int     *tab; 
 
        i = 0; 
        j = 0; 
        result = 0; 
 
        tab = malloc(sizeof(int) * 41); 
        if (!tab) 
                return (0); 
        while (str[i]) 
        { 
                if (str[i] == ' ' || str[i] == ':') 
                { 
                        while (str[i] != '\n') 
                                i++; 
                } 
                else if (str[i] >= '0' && str[i] <= '9') 
                { 
                        result = 0; 
                        while (str[i] >= '0' && str[i] <= '9') 
                        { 
                                result *= 10; 
                                result += str[i] - '0'; 
                                i++; 
                        } 
                        tab[j] = result; 
                        j++; 
                } 
                else 
                        i++; 
        } 
        return (tab); 
}


