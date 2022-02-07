/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:39:25 by mbishop-          #+#    #+#             */
/*   Updated: 2022/02/07 12:42:43 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_append(int fd, char *buffer, char *remainder)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		temp = remainder;
		remainder = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (remainder);
}

/* bytes_read is assigned a value to make it run.
 * If the vlue is less than one there is an error. 
 * If the value is zero it is the end of the file.
 * If there is no remainder, give it the value of an empty strdup.
 * Temp is assigned the value of remainder, and remainder is assigned 
 * the value of strjoin, which is temp with buffer attached to the end.
 * Temp is freed. If a newline is found in buffer the loop is broken.
 * Remainder is then returned.*/

static char	*update_new_line(char *line)
{
	size_t	idx;
	char	*remainder;

	idx = 0;
	while (line[idx] != '\n' && line[idx] != '\0')
		idx++;
	if (line[idx] == '\0' || line[1] == '\0')
		return (0);
	remainder = ft_substr(line, idx + 1, ft_strlen(line) - idx);
	if (*remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line[idx + 1] = '\0';
	return (remainder);
}

/* idx is set to zero and incremented while the value is not a newline
 * or null terminator. After incrementing through, if the value is a
 * null terminator, return zero.
 * Remainder is assigned the value of substr, which is created from 
 * line with starting point of idx plus one, and the length of line.
 * If there is no value in ramainder, it is freed. 
 * Otherwise, return remainder.*/

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = read_and_append(fd, buffer, remainder);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remainder = update_new_line(line);
	return (line);
}

/* Line is the string we want to return, remainder holds the 
 * leftovers of line only within it's file (hence static char).
 * If there are undefined stdin values (e.g. in fd or BUFFER_SIZE)
 * it will return zero. Buffer is assigned its value; if there
 * is no buffer return zero. 
 * Line is assigned the value of read_and_append which is made up of
 * fd, buffer, and remainder. Buffer is freed.
 * If there is no line, return null.
 * Remainder is assigned the value of update_new_line, which is the
 * line we want to return to get the end result! */
