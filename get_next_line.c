/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:20:16 by ccaballe          #+#    #+#             */
/*   Updated: 2022/11/02 18:35:04 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char *str)
{
	free (str);
	return (NULL);
}

char	*ft_read_file(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	buffer[0] = '\0';
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (ft_free(storage));
		}
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (!storage)
			return (ft_free(buffer));
	}
	free(buffer);
	return (storage);
}

char	*ft_get_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	if (storage[i] == '\0')
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] != '\n')
		line = (char *)malloc(sizeof(char) * (i + 1));
	else
		line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (ft_free(storage));
	i = 0;
	while (storage[i] != '\n' && storage[i] != '\0')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage [i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_clean_storage(char *storage)
{
	char	*clean;
	int		i;
	int		j;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\0')
		return (ft_free(storage));
	j = 0;
	clean = (char *)malloc(sizeof(char) * (ft_strlen(storage) - i));
	if (!clean)
		return (NULL);
	while (storage[++i])
	{
		clean[j] = storage[i];
		j++;
	}
	clean[j] = '\0';
	free(storage);
	return (clean);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read_file(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_get_line(storage);
	storage = ft_clean_storage(storage);
	return (line);
}
