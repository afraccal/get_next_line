/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:42:54 by afraccal          #+#    #+#             */
/*   Updated: 2023/02/01 10:55:07 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	s = malloc (sizeof(char) * (i + 2));
	if (s == '\0')
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*reminder(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*line;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	line = malloc(sizeof(char) * ((len - i) + 1));
	if (!line)
		return (NULL);
	i++;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	free(str);
	return (line);
}

char	*read_str(int fd, char *str)
{
	char	*buff;
	char	*ret;
	int		i;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == '\0')
		return (0);
	i = 1;
	buff[0] = '\0';
	ret = ft_strchr(buff, '\n');
	while (!ret && i != '\0')
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (0);
		}
		buff[i] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*new_line;

	new_line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	line[fd] = read_str(fd, line[fd]);
	if (!line[fd])
		return (0);
	new_line = get_line(line[fd]);
	line[fd] = reminder(line[fd]);
	return (new_line);
}
