/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:21:46 by ccaballe          #+#    #+#             */
/*   Updated: 2022/11/02 16:49:50 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strlen(char *s);
char	*ft_strjoin(char *str_file, char *buff);
char	*ft_strchr(char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);

#endif