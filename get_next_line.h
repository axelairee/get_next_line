/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:48:46 by abolea            #+#    #+#             */
/*   Updated: 2023/12/12 14:47:44 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char            *get_next_line(int fd);
static int        endline_checker(char    *buff);
char    *ft_strjoin(char *s1, char* s2);
char            *ft_strdup(char *s);
size_t     ft_strlen(char *s);
char        *ft_substr(char *s, unsigned int start, unsigned int len);
char            *ft_strchr(const char *s, int c);
static	int     tmp_len(char *tmp);
char			*get_all(int fd, char *buff, char *res);
char *get_next_backline(int fd, char *buff,char *res, char *static_str);
char *get_before_backline(int fd, char *buff, char *res, char *static_str);

#endif