/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:22:00 by abolea            #+#    #+#             */
/*   Updated: 2023/12/12 14:49:47 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
    static char buff[BUFFER_SIZE];
    char *res;
    int ret;
	char *tmp;

    res = ft_strdup("");
    while (endline_checker(buff) == 0)
    {
        ret = read(fd, buff, BUFFER_SIZE);
        if (ret == 0)
            break;
        else if (ret == -1)
        {
            free(res);
            return (NULL);
        }
		res = ft_strjoin(res, buff);
    }
	if (endline_checker(buff) == 1)
	{
		tmp = ft_strchr(buff, '\n');
		res = ft_substr(res, ft_strlen(tmp), tmp_len(tmp));
		printf("\n%s\n", tmp);
	}
    return (res);
}


static	int     tmp_len(char *tmp)
{
	int	i;

	i = 0;
	while(tmp[i] != '\n')
		i++;
	i++;
	return(i);
}

static int	endline_checker(char *buff)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char    *ft_substr(char *s, unsigned int start, unsigned int len)
{
	char			*s2;
    unsigned int	i;
    size_t			len_s;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (NULL);
	if (len > len_s - start)
		len = len_s - start;
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (len--)
		s2[i++] = s[start++];
	s2[i] = '\0';
	return (s2);
}

char *ft_strchr(const char *s, int c)
{	
	if(c < 0 || c > 127)
		return ((char *)s);
	while (*s)
	{
		if(*s == c)
			return((char *)s);
		s++;
	}
	if(c == '\0')
		return((char *)s);
	return (NULL);
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
	while (j < ft_strlen(s2) && s2[j] != '\n')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

char	*ft_strdup(char *s)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!s2)
		return (NULL);
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

#include <stdio.h>
int		main(void)
{
	int fd = open("res.txt", O_RDONLY);
	char	*str;
    int		lines = 0;

	while (lines < 1)
	{
		str = get_next_line(fd);
		printf ("%s", str);
		free(str);
		lines++;
	}
}