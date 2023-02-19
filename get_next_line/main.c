/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:54:20 by afraccal          #+#    #+#             */
/*   Updated: 2023/02/01 14:54:50 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		i;
	int		fd;
	/*int	fd1;
	int		fd2;
	int		fd3;
	int 	fd4;*/
	/*fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	fd4 = open("tests/test4.txt", O_RDONLY);*/
	i = 0;
	(void)argc;
	fd = open (argv[1], O_RDONLY);
	while (i < 3)
	{
		/*line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd4);
		printf("line [%02d]: %s", i, line);
		free(line);*/
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	/*close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);*/
	close(fd);
	return (0);
}