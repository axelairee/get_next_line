/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:31:08 by rasamad           #+#    #+#             */
/*   Updated: 2023/12/20 12:03:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif
#include <fcntl.h>
#include <unistd.h>
# include <stdlib.h>
# include <stdint.h>


void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(char *s);
char	*ft_memcpy(char *dst, char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_buff(char *buff);
int		ft_check_buff2(char *buff);
char	*get_next_line(int fd);
char *print_line(char *line, char *buff, int check_buff, int fd);
void *verif_read(char *line, char *buff, int check_buff, int check_read);

#endif