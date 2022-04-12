/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:09:14 by yaktas            #+#    #+#             */
/*   Updated: 2022/04/12 17:14:24 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *satiralmaca(int fd, char *asildizi)
{
	char *buff;
	int read_test;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buff)
		return ;
	read_test = 1;
	while(!ft_strchr(asildizi, '\n') && read_test != 0)
	{
		read_test = read(fd, buff, BUFFER_SIZE);
		if(read_test == -1)
		{
			free(buff);
			return ;
		}
		buff[read_test] = '\0';
		

	}
}

char	*get_next_line(int fd)
{
	static char *asildizi;
	char *satir;

	if(fd < 0 || BUFFER_SIZE < 1)
		return ;
	asildizi = satiralmaca(fd, asildizi);
}

int main()
{
	open("text.txt", 0);
	int fd = -1;
	printf("%s", get_next_line(fd));
}