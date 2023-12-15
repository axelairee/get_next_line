/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:29:35 by abolea            #+#    #+#             */
/*   Updated: 2023/12/15 18:29:38 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

int	buff_checker(char *buff);
char *get_next_line(int fd);
void	*ft_memcpy(void *dest, const void *src);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif