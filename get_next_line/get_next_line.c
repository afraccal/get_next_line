/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:56:45 by afraccal          #+#    #+#             */
/*   Updated: 2023/01/28 15:37:50 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *) malloc (i + 2);
	if (!s)
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

char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	s = (char *) malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	free(str);
	return (s);
}

char	*read_str(int fd, char *str)
{
	char	*buff;
	int		i;
	char	*ret;

	buff = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	i = 1;
	ret = ft_strchr(str, '\n');
	while (!ret && i != '\0')
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free (buff);
			return (0);
		}
		buff[i] = '\0';
		str = ft_strjoin (str, buff);
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*new_line;

	new_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = read_str(fd, line);
	if (!line)
		return (0);
	new_line = ft_get_line(line);
	line = ft_new_str(line);
	return (new_line);
}
