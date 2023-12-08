/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:18:27 by abolea            #+#    #+#             */
/*   Updated: 2023/12/08 18:42:18 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

#define BUFFER_SIZE 5

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*s3;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!s3)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		s3[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2) && s2[j - 1] != '\n')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}
int	ft_check_buff(char *buff)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return(0);
}
char	*get_next_line(int fd)
{
	char *buff;
	char *res;

	buff = malloc(BUFFER_SIZE * sizeof(char));
	if (!buff)
		return (NULL);
	while (ft_check_buff(buff) == 0)
	{
		read(fd, buff, BUFFER_SIZE);
		res = ft_strjoin(res, buff);
	}
	return (res);
}

#include <fcntl.h>
#include <stdio.h>


int main()
{
	int fd;

	fd = open("res.txt", O_RDONLY);
	

	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
	return (0);
}
