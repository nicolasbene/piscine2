/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:02:05 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/19 19:18:53 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	len;
	int	j;

	len = ft_strlen(base);
	i = 0;
	if (base[0] == '\0' || len == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (j < len)
		{	
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	long	base_len;

	nb = nbr;
	base_len = ft_strlen(base);
	if (check_base(base) == 1)
	{
		if (nb < 0)
		{
			ft_putchar ('-');
			nb *= -1;
		}
		if (nb >= (base_len))
		{
			ft_putnbr_base(nb / base_len, base);
			ft_putnbr_base(nb % base_len, base);
		}
		else
			ft_putchar(base[nb]);
	}

}
int		main(void)
{
	ft_putnbr_base(-12, "01");
	printf("\n");
	ft_putnbr_base(-40, "poneyvif");
	printf("\n");
	ft_putnbr_base(-894867, "0123456789");
	printf("\n");
	ft_putnbr_base(-2147483648, "0123456789");
}
