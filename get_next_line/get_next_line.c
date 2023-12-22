/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famillebolea <famillebolea@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:59:51 by abolea            #+#    #+#             */
/*   Updated: 2023/12/22 19:24:49 by famillebole      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = "\0";
	int			check_read;
	char		*line;
	static int	check_buff = 0;

	line = check_input_and_init_line(fd);
	if (!line)
		return (free(line), NULL);
	if (buff[0] != 0)
	{
		ft_memcpy(buff + 0, buff + ft_check_buff(buff, 2));
		line = ft_strjoin(line, buff);
		if (!line)
			return(free(line), NULL);
		check_buff = ft_check_buff(buff, 1);
		if (buff[check_buff] == '\n')
			return (line);
	}
	check_read = read(fd, buff, BUFFER_SIZE);
	buff[check_read] = 0;
	if (check_read < 0)
		return (ft_free(buff, line));
	if (check_read <= 0 && check_buff == 0)
		return (free(line), NULL);
	return (print_line(line, buff, &check_buff, fd));
}

char	*ft_free(char *buff, char *line)
{
	ft_bzero(buff, 1);
	free(line);
	return (NULL);
}

char	*check_input_and_init_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1 * sizeof(char));
	if (line)
		line[0] = '\0';
	return (line);
}

char	*print_line(char *line, char *buff, int *check_buff, int fd)
{
	*check_buff = ft_check_buff(buff, 1);
	if (*check_buff < BUFFER_SIZE)
	{
		line = ft_strjoin(line, buff);
		if (!line)
			return(free(line), NULL);
	}
	else
	{
		while (*check_buff == BUFFER_SIZE)
		{
			line = ft_strjoin(line, buff);
			if (!line)
				return(free(line), NULL);
			buff[read(fd, buff, BUFFER_SIZE)] = 0;
			*check_buff = ft_check_buff(buff, 1);
		}
		line = ft_strjoin(line, buff);
		if (!line)
			return(free(line), NULL);
	}
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!s3)
		return (free(s1), NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j - 1] != '\n')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (free(s1), s3);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main()
// {
// 	int fd = open("gnl.txt", O_RDONLY);
// //	char *str = ;
// 	int i = 0;

// 	while (i < 48)
// 	{
// 		printf("%s", get_next_line(fd));
// //		free(str);
// 		i++;
// 	}
// 	close(fd);
// 	return 0;
// }
