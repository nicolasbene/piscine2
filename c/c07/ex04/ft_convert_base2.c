/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:14:58 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/20 19:28:08 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	j;
	int	len;

	len = 0;
	while (base[len])
		len++;
	i = 0;
	if (base[0] == '\0' || len == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	white_space(char *str, int *ptr_i)
{
	int	i;
	int	sign;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*ptr_i = i;
	return (sign);
}

int	nb_base(char str, char *base)
{
	long	nb;

	nb = 0;
	while (base[nb])
	{
		if (str == base[nb])
			return (nb);
		nb++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		base_len;
	long	nb;
	long	result;

	i = 0;
	result = 0;
	nb = 0;
	sign = 1;
	base_len = check_base(base);
	if (base_len >= 2)
	{
		sign = white_space(str, &i);
		nb = nb_base(str[i], base);
		while (nb != -1)
		{
			result = (result * base_len) + nb;
			i++;
			nb = nb_base(str[i], base);
		}
		return (sign * result);
	}
	return (0);
}
