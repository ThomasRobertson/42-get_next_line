/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:01:46 by troberts          #+#    #+#             */
/*   Updated: 2022/05/11 20:11:35 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		printf("No arg");
		return (1);
	}
	if (ac == 2)
	{
		int fd = open(av[1], O_RDONLY);
		char	*line;
		while ((line = get_next_line(fd)))
		{
			printf("%s", line);
			free(line);
		}
		close(fd);
	}
	if (ac == 3)
	{
		int		fd1 = open(av[1], O_RDONLY);
		int		fd2 = open(av[2], O_RDONLY);
		char	*line1;
		char	*line2;
		while ((line1 = get_next_line(fd1)) && (line2 = get_next_line(fd2)))
			printf("%s\n%s\n", line1, line2);
	}
}
