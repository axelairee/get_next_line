/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:28:50 by abolea            #+#    #+#             */
/*   Updated: 2023/12/15 17:22:36 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src)
{
	size_t			i;
	char			*tmp1;
	char			*tmp2;

	i = 0;
	tmp1 = (char *)dest;
	tmp2 = (char *)src;
	if ((char *)dest == NULL && (char *)src == NULL)
		return (NULL);
	while (tmp2[i])
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	tmp1[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
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
	size_t		len_s2;
	size_t		len_s1;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (free(s1), NULL);
	s3 = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!s3)
		return (free(s1),NULL);
	while (i < len_s1)
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j - 1] != '\n')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}
