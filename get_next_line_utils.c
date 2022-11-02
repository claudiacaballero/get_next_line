/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:21:03 by ccaballe          #+#    #+#             */
/*   Updated: 2022/11/02 16:49:44 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*a;
// 	unsigned char	*b;

// 	i = 0;
// 	a = (unsigned char *)dst;
// 	b = (unsigned char *)src;
// 	if (!dst && !src)
// 		return (NULL);
// 	while (i < n)
// 	{
// 		a[i] = b[i];
// 		i++;
// 	}
// 	return (dst);
// }

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*s3;
// 	size_t	i;
// 	size_t	l;

// 	l = ft_strlen(s1);
// 	s3 = (char *)malloc(sizeof(char) * (l + ft_strlen(s2) + 1));
// 	if (!s3)
// 		return (NULL);
// 	if (l != 0)
// 		ft_memcpy(s3, s1, l);
// 	i = 0;
// 	while (s2[i] != '\0')
// 	{
// 		s3[l + i] = s2[i];
// 		i++;
// 	}
// 	s3[l + i] = '\0';
// 	free(s1);
// 	return (s3);
// }

char	*ft_strjoin(char *str_file, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!str_file)
	{
		str_file = (char *)malloc(1 * sizeof(char));
		str_file[0] = '\0';
	}
	if (!str_file || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(str_file) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str_file)
		while (str_file[++i] != '\0')
			str[i] = str_file[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(str_file);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*a;

	a = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (&a[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&a[i]);
	else
		return (NULL);
}
