/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:51:16 by ruida-si          #+#    #+#             */
/*   Updated: 2024/11/08 15:51:19 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 20

static char	*readfile(int fd, char *buffer, char *line, int buffer_size)
{
	int		b_read;
	char	*temp;

	b_read = 1;
	while (b_read)
	{
		b_read = read(fd, buffer, buffer_size);
		if (b_read <= 0)
			break ;
		buffer[b_read] = '\0';
		if (!line)
			line = ft_strdup("");
		temp = line;
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		free(temp);
		temp = NULL;
		if (ft_strchr(line, '\n'))
			break ;
	}
	free(buffer);
	return (line);
}

static char	*next_call(char *line)
{
	char	*temp;
	char	*backup;

	temp = ft_strchr(line, '\n');
	if (temp)
	{
		backup = ft_strdup(temp +1);
		*temp = '\0';
		return (backup);
	}
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = readfile(fd, buffer, backup, BUFFER_SIZE);
	if (!line)
		return (NULL);
	backup = next_call(line);
	return (line);
}

/* int main()
{
	int fd = open("get_next_line_utils.c", O_RDWR | O_CREAT, 0644);
	printf("%i", fd);
	char *s = get_next_line(fd);
	printf(".%s.", s);
	free(s);
	s = get_next_line(fd);
	printf(".%s.", s);
	free(s);
} */
