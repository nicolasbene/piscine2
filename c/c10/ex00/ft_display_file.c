/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:17:11 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/27 15:17:14 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	display_file(char *filename)
{
	int		fd;
	int		length;
	char	buffer[256];

	length = 1;
	fd = open(filename, O_RDONLY);
	while (length > 0)
	{
		length = read(fd, buffer, 256);
		write(1, buffer, length);
	}
	close(fd);
}
