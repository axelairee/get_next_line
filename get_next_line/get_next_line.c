/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:26:55 by abolea            #+#    #+#             */
/*   Updated: 2023/12/14 18:23:12 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	buff_checker(char *buff)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buff[i] == '\n' || buff[i] == '\0')
			return (i);
		i++;
	}
	return (i);
}

char *get_next_line(int fd)
{
	static char buff[BUFFER_SIZE + 1] = "\0";
	char *line;
	int check_read;
	static int check_buff = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1 * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (buff[0] != 0)
	{
		ft_memcpy(buff + 0, buff + check_buff + 1);
		line = ft_strjoin(line, buff);
		check_buff = buff_checker(buff);
		if (buff[check_buff] == '\n')
			return (line);
	}
	check_read = read(fd, buff, BUFFER_SIZE);
	buff[check_read] = 0;
	if (check_read <= 0 && check_buff == 0)
	{
		free(line);
		return (NULL);
	}
	check_buff = buff_checker(buff);
	if (check_buff < BUFFER_SIZE)
		line = ft_strjoin(line, buff);
	else
	{
		while (check_read > 0 && check_buff == BUFFER_SIZE)
		{
			line = ft_strjoin(line, buff);
			check_read = read(fd, buff,BUFFER_SIZE);
			buff[check_read] = 0;
			if (check_read == -1)
				return (NULL);
			check_buff = buff_checker(buff);
		}
		line = ft_strjoin(line, buff);
	}
	return (line);
}

#include <stdio.h>
int	main()
{
	int fd;
	
	fd = open("gnl.txt", O_RDONLY);
	int i = 0;
	while (i < 2)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	close(fd);
	return 0;
}
