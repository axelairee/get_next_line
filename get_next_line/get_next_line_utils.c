/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:38:58 by rasamad           #+#    #+#             */
/*   Updated: 2023/12/20 11:43:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


void	ft_bzero(void *s, size_t n)
{
	char	*temp;
	size_t	i;

	temp = (char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
}

size_t	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);	
}

char	*ft_memcpy(char *dst, char *src)
{
	int	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}


char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*tmp;
	
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	tmp = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!tmp)
		return (free(s1), NULL);
	while (i < len_s1)
	{
		tmp[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] && s2[i-1] != '\n')
	{
		tmp[len_s1 + i] = s2[i];
		i++;	
	}
	tmp[len_s1 + i] = 0;
	free(s1);
	return (tmp);
}

int		ft_check_buff(char *buff)
{
	size_t i = 0;
	
	while (i < BUFFER_SIZE)
	{
		if(buff[i] == '\n' || buff[i] == '\0')
			return(i);
		i++;
	}
	return(i);
}

int		ft_check_buff2(char *buff)
{
	size_t i = 0;
	
	while (i < BUFFER_SIZE)
	{
		if(buff[i] == '\n')
			return(i + 1);
		i++;
	}
	return(i);
}