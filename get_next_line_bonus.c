/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:20:30 by yaktas            #+#    #+#             */
/*   Updated: 2022/05/25 13:34:07 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//ilk satiri /n bulana kadar okur. buffer size in boyutuna
//gore siradaki satirdan karakter alabilir.
char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}
//read int dondurur.
//read fonksiyonu fdnin icinde buffersize kadar okuyup buffa atıyor
//buffun uzunlugunu donduruyor.

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = ft_read_to_left_str(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return (line);
}

/* int main()
 {
 	int fd;
 	fd = open("a.txt",O_RDONLY);
 	printf("%s", get_next_line(fd));
 	fd = open("b.txt",O_RDONLY);
 	printf("%s", get_next_line(fd));
 	fd = open("c.txt",O_RDONLY);
 	printf("%s", get_next_line(fd));
 	printf("%s", get_next_line(3));
} */