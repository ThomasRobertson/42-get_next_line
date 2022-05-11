/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:02:30 by troberts          #+#    #+#             */
/*   Updated: 2022/05/11 20:14:02 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# define FD_MAX 10240

typedef struct s_fd
{
	int			fd;
	char		buff[BUFFER_SIZE + 1];
	size_t		len_read;
	int			nl_found;
	size_t		thread;
	char		*line;
	struct s_fd	*next;
}				t_fd;

/*
** @brief Get the next line of a file descriptor, without the newline.
** 
** @param fd file descriptor of file to read
** @param line value of what has been read
** @return int 1 if a line as been read, 0 for EOF and -1 if an error occured
*/
char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif