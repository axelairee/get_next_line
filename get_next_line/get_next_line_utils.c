/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:00:18 by abolea            #+#    #+#             */
/*   Updated: 2023/12/20 22:00:31 by abolea           ###   ########.fr       */
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
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
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

char	*ft_strdup(char *s)
{
	size_t	j;
	char	*tmp;

	j = 0;
	if (!s)
		return (NULL);
	tmp = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tmp)
		return (NULL);
	while (j < ft_strlen(s) && s[j])
	{
		tmp[j] = s[j];
		j++;
	}
	tmp[j] = '\0';
	return ((char *)tmp);
}

int	ft_check_buff(char *buff, int choice)
{
	size_t	i;

	i = 0;
	if (choice == 1)
	{
		while (i < BUFFER_SIZE)
		{
			if (buff[i] == '\n' || buff[i] == '\0')
				return (i);
			i++;
		}
	}
	if (choice == 2)
	{
		while (i < BUFFER_SIZE)
		{
			if (buff[i] == '\n')
				return (i + 1);
			i++;
		}
	}
	return (i);
}
