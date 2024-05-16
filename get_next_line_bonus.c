/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:54:27 by psangunna         #+#    #+#             */
/*   Updated: 2024/05/16 18:54:35 by psangunna        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
This function reads from a file descriptor (fd) and appends the content to 
a buffer (file_buf) until it finds a newline character or reaches the end of 
the file. It dynamically allocates memory for a temporary buffer (buf), reads 
data into it, and then appends it to the main buffer (file_buf). It returns 
the updated file_buf.
*/
char	*ft_read_from_file(char *file_buf, int fd)
{
	int		char_read;
	char	*buf;

	char_read = 1;
	while (!ft_find_nextline(file_buf) && char_read != 0)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return (NULL);
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read < 0)
		{
			free(buf);
			if (file_buf != NULL)
				free(file_buf);
			return (NULL);
		}
		buf[char_read] = '\0';
		file_buf = ft_append_char_read(file_buf, buf);
		free(buf);
	}
	return (file_buf);
}

/*
This function extracts the next line from a buffer (file_buf) that contains 
file content. It determines the length of the line, allocates memory for the
line, copies the line into the new memory, and returns it.
*/
char	*ft_get_line(char *file_buf)
{
	int		line_len;
	char	*show_line;

	line_len = 0;
	if (!file_buf[0])
		return (NULL);
	line_len = ft_len_to_newline(file_buf);
	show_line = malloc(line_len + 1);
	if (show_line == NULL)
		return (NULL);
	ft_copy_line(file_buf, show_line);
	return (show_line);
}

/*
This function cleans up the buffer (file_buf) by removing the content up to 
and including the first newline character. It allocates memory for the 
remaining content, copies it into the new memory, and frees the original buffer.
*/
char	*ft_clean_file_buf(char	*file_buf)
{
	char	*last_line;
	int		i;
	int		k;

	i = 0;
	if (!file_buf)
		return (NULL);
	while (file_buf[i] != '\0' && file_buf[i] != '\n')
		++i;
	if (!file_buf[i])
	{
		free(file_buf);
		return (NULL);
	}
	if (file_buf[i] == '\n')
		i++;
	last_line = malloc(sizeof(char) * (ft_strlen(file_buf) - i + 1));
	if (!last_line)
		return (NULL);
	k = 0;
	while (file_buf[i] != '\0' && file_buf[i])
		last_line[k++] = file_buf[i++];
	last_line[k] = '\0';
	free(file_buf);
	return (last_line);
}

/*
This function serves as an interface to extract lines from a file. 
It reads from a file descriptor (fd) using ft_read_from_file, retrieves 
the next line using ft_get_line, and then cleans up the buffer using 
ft_clean_file_buf, returning the next line extracted from the file.
*/
char	*get_next_line(int fd)
{
	static char		*file_buf[MAX_FD];
	char			*show_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file_buf[fd] = ft_read_from_file(file_buf[fd], fd);
	if (file_buf[fd] == NULL)
		return (NULL);
	show_line = ft_get_line(file_buf[fd]);
	file_buf[fd] = ft_clean_file_buf(file_buf[fd]);
	return (show_line);
}
