/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:17:55 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/20 16:16:51 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	main()
{
	char src[] = "Hello";
	char dest[] = "Hwpmpfmwpfm";
	char dest1[] = "wfmomfowm";

	printf("%s", ft_strncpy(dest, src, 3));
	printf("\n%s", strncpy(dest1, src, 3));
	printf("\n%s", ft_strncpy(dest, src, 5));
	printf("\n%s", strncpy(dest1, src, 5));
	printf("\n%s", ft_strncpy(dest, src, 7));
	printf("\n%s", strncpy(dest1, src, 7));
}
