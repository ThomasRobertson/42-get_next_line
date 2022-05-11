/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:01:35 by troberts          #+#    #+#             */
/*   Updated: 2022/05/11 20:06:17 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

size_t	get_len_of_line(char *buffer)
{
	size_t	len;

	len = 0;
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len++;
	if (buffer[len] == '\n')
		len++;
	return (len);
}

ssize_t	get_read(int fd, char **buffer)
{
	size_t		i;
	ssize_t	len_read;

	i = 0;
	free(*buffer);
	write(1, "36:get_read : Buffer free.\n", 28);
	*buffer = NULL;
	*buffer = malloc(sizeof(**buffer) * (BUFFER_SIZE + 1));
	write(1, "39:get_read : Malloc of buffer\n", 32);
	if (*buffer == NULL)
		return (0);
	while (i < (BUFFER_SIZE + 1))
	{
		(*buffer)[i] = 0;
		i++;
	}
	len_read = read(fd, *buffer, BUFFER_SIZE);
	if (len_read <= 0)
	{
 		free(*buffer);
		*buffer = NULL;
		write(1, "52:get_read : Buffer free because len_read <= 0.\n", 50);
		return(len_read);
	}
	else
		return (len_read);
}

char	*get_line(char **buffer, int fd, int *nl_found)
{
	ssize_t	len_read;
	char	*line;
	size_t	len_line;
	char	*buff_tmp;

	if (*buffer == NULL || ft_strlen(*buffer) == 0)
	{
		if (*buffer == NULL)
			write(1, "69:get_line : Buffer is null, getting new read.\n", 49);
		else if (ft_strlen(*buffer) == 0)
			write(1, "71:get_line : Buffer len is 0, getting new read\n", 49);
		len_read = get_read(fd, buffer);
		if (len_read <= 0)
		{
			write(1, "75:get_line : len_read <= 0, returning NULL.\n", 46);
			return(NULL);
		}
	}
	len_line = get_len_of_line(*buffer);
	if ((*buffer)[len_line - 1] == '\n')
		*nl_found = 1;
	write(1, "82: get_line : Malloc of line\n", 31);
	line = malloc(len_line + 1);
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, *buffer, len_line + 1);
	buff_tmp = ft_strdup((*buffer) + len_line);
	write(1, "88: get_line : Free/Malloc buffer\n", 35);
	free(*buffer);
	*buffer = buff_tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_MAX];
	char		*line_tmp;
	int			nl_found;
	char		*line;
	char		*new_line;

	if (fd < 0)
		return (NULL);
	nl_found = 0;
	write(1, "105: gnl : new call to function.\n", 34);
	line = get_line(&buffer[fd], fd, &nl_found);
	if (line == NULL)
	{
		write(1, "109: gnl : returning null because line is null\n", 48);
		return (NULL);
	}
	while (nl_found == 0)
	{
		write(1, "114: gnl : getting into the while\n", 34);
		new_line = get_line(&buffer[fd], fd, &nl_found);
		if (new_line == NULL)
		{
			write(1, "118: gnl : new_line null, returning only line\n", 47);
			return (line);
		}
		line_tmp = malloc(sizeof(*line) * (ft_strlen(line)
					+ ft_strlen(new_line) + 1));
		write(1, "123: gnl : malloc of line_tmp\n", 31);
		if (line_tmp == NULL)
			return (NULL);
		line_tmp = ft_strjoin(line, new_line);
		free(new_line);
		free(line);
		line = line_tmp;
		write(1, "130: gnl : new_line and line_tmp free\n", 39);
	}
	write(1, "132: gnl : returning line\n", 27);
	return (line);
}
