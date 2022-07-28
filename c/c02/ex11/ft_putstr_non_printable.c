/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:13:48 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/10 20:21:06 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_char_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	*str;

	str1 = (unsigned char *)str;
	i = 0;
	while (str1[i] != '\0')
	{
		if (ft_char_is_printable(str1[i]) == 1)
			ft_putchar(str1[i]);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[str1[i] / 16]);
			ft_putchar("0123456789abcdef"[str1[i] % 16]);
		}
		i++;
	}
}
