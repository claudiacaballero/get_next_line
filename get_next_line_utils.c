/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:21:03 by ccaballe          #+#    #+#             */
/*   Updated: 2022/11/02 18:21:55 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
/*
char	*ft_strjoin(char *storage, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!storage)
	{
		storage = (char *)malloc(1 * sizeof(char));
		if (storage)
			storage[0] = '\0';
	}
	if (!storage || !buffer)
		return (ft_free(storage, buffer));
	str = malloc(sizeof(char) * ((ft_strlen(storage) + ft_strlen(buffer)) + 1));
	if (!str)
		return (ft_free(storage, buffer));
	i = -1;
	j = 0;
	if (storage)
		while (storage[++i] != '\0')
			str[i] = storage[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[i] = '\0';
	free(storage);
	return (str);
}
*/

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (ft_free(s1, ""));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
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
