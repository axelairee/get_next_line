/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:14:36 by rasamad           #+#    #+#             */
/*   Updated: 2023/12/20 12:05:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buff[BUFFER_SIZE + 1] = "\0";
	int check_read;
	char *line;
	static int check_buff = 0;
	
	line = malloc(1 * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (NULL);
	line[0] = 0;
	if (buff[0] != 0)
	{
		ft_memcpy(buff + 0, buff + ft_check_buff2(buff));
		line = ft_strjoin(line, buff);
		check_buff = ft_check_buff(buff);
		if (buff[check_buff] == '\n')
			return (line);
	}
	check_read = read(fd, buff, BUFFER_SIZE);
	buff[check_read] = 0;
	if (verif_read(line, buff, check_buff, check_read) != NULL)
		check_buff = (int)verif_read(line, buff, check_buff, check_read);
	else
		return (free(line),NULL);
	line = print_line(line, buff, check_buff, fd);
	return (line);
}

void *verif_read(char *line, char *buff, int check_buff, int check_read)
{
    if (check_read < 0)
    {
        ft_bzero(buff, 1);
        free(line);
        return((char *)NULL);
    }
    
    if (check_read <= 0)
    {
        free(line);
        return((char *)NULL);
    }
    else
    {
        check_buff = ft_check_buff(buff);
        return ((void *)check_buff);
    }
}

char *print_line(char *line, char *buff, int check_buff, int fd)
{
	int check_read;

	check_read = 0;
	if (check_buff < BUFFER_SIZE)
		line = ft_strjoin(line, buff);
	else
	{
		while (check_read > 0 && check_buff == BUFFER_SIZE)
		{
			line = ft_strjoin(line, buff);
			check_read = read(fd, buff, BUFFER_SIZE);
			buff[check_read] = 0;
			check_buff = ft_check_buff(buff);
		}
		line = ft_strjoin(line, buff);
	}
	return (line);
}

#include <stdio.h>
int main()
{
	int fd = open("gnl.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return 1;
	}
	char* line;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//char *line;
	//printf("line = |%s|\n", line);
	// free(line);
	// line = get_next_line(fd);
	// printf("line = |%s|\n", line);
	int i = 0;
	while (i < 9)
	{
		// Traitement de la ligne ici
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
		// Libérer la mémoire allouée pour chaque ligne
	}

	free(line);
	close(fd);
	return 0;
}

/*int    main(void)
{
    int fd = open("gnl.txt", O_RDONLY);
    char    *str;
    int    lines = 0;
    int    i = 0;
    
    while(lines < 4)
    {
        if (i == 2)
            fd++;
        if (i == 3)
        {
            close(fd);
            fd = open("gnl.txt", O_RDONLY);
        }
        str = get_next_line(fd);
        printf ("%s", str);
        free(str);
        lines++;
        i++;
    }
}*/