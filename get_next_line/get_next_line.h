/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:00:06 by abolea            #+#    #+#             */
/*   Updated: 2023/12/20 22:00:33 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <unistd.h>
# include <stdlib.h>

char	*ft_strdup(char *s);
char	*check_input_and_init_line(int fd);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(char *s);
char	*ft_memcpy(char *dst, char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_buff(char *buff, int choice);
char	*get_next_line(int fd);
char	*ft_free(char *buff, char *line);
char	*print_line(char *line, char *buff, int *check_buff, int fd);

#endif