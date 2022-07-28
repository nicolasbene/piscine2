/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:17:07 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/25 14:53:17 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	check_base(char *base);
int	white_space(char *str, int *ptr_i);
int	nb_base(char str, char *base);
int	ft_atoi_base(char *str, char *base);

int	len_nbr(int nbr, char *base, int len)
{
	unsigned int	base_len;
	unsigned int	nb;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		nb = nbr * -1;
		len++;
	}
	else
		nb = nbr;
	while (nb >= base_len)
	{
		nb /= base_len;
		len++;
	}
	len++;
	return (len);
}

void	ft_putnbr_base_v2(int nbr, char *base, char *nbrf)
{
	int		len_base;
	long	nb;
	int		i;
	int		len_nbrf;

	len_base = ft_strlen(base);
	len_nbrf = len_nbr(nbr, base, 0);
	nb = nbr;
	i = 0;
	if (nb < 0)
	{
		nbrf[0] = '-';
		nb *= -1;
		i = 1;
	}
	len_nbrf--;
	while (nb >= len_base)
	{
		nbrf[len_nbrf] = base[nb % len_base];
		nb /= len_base;
		len_nbrf--;
	}
	if (nb < len_base)
		nbrf[i] = base[nb];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*finalnbr;
	int		mednbr;
	int		len_nbrf;

	if (check_base(base_to) == 0 || check_base(base_from) == 0)
		return (0);
	mednbr = ft_atoi_base(nbr, base_from);
	len_nbrf = len_nbr(mednbr, base_to, 0);
	finalnbr = (char *)malloc(sizeof(char) * (len_nbrf + 1));
	if (!finalnbr)
		return (0);
	ft_putnbr_base_v2(mednbr, base_to, finalnbr);
	finalnbr[len_nbrf] = '\0';
	return (finalnbr);
}
