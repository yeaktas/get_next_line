/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:09:14 by yaktas            #+#    #+#             */
/*   Updated: 2022/04/18 13:13:18 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*satiralmaca(int fd, char *asildizi)
{
	char	*buff;
	int		okunanbyte;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return ;
	okunanbyte = 1;
	while (ft_strchr(asildizi, '\n') && okunanbyte != 0)
	{
		okunanbyte = read(fd, buff, BUFFER_SIZE);
		if (okunanbyte == -1)
		{
			free(buff);
			return ;
		}
		buff[okunanbyte] = '\0';
		asildizi = ft_strjoin(asildizi, buff);
	}
	free(buff);
	return (asildizi);
}

char	*get_next_line(int fd)
{
	static char	*asildizi;
	char		*satir;

	if (fd < 0 || BUFFER_SIZE < 1)
		return ;
	asildizi = satiralmaca(fd, asildizi);
	if (!asildizi)
		return ;
	satir = ft_get_line(asildizi);
	asildizi = ft_new_left_str(asildizi);
	return (satir);
}
