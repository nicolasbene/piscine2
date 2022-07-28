/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:21:02 by nibenoit          #+#    #+#             */
/*   Updated: 2022/07/23 14:21:04 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_process_file(int fd)
{
        char    buffer[1024];
        int             length;
        char    *content;

        content = (char *)malloc(sizeof(char) * 1);
        if (!content)
                return (NULL);
        content[0] = 0;
        length = 1;
        while (length > 0)
        {
                length = read(fd, buffer, 1024);
                if (length > 0)
                {
                        content = ft_strncat_malloc(content, buffer, length);
                        if (!content)
                                return (NULL);
                }
        }
        return (content);
}
