/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:54:54 by psangunna         #+#    #+#             */
/*   Updated: 2024/05/16 18:54:59 by psangunna        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

/*
This function copies characters from a file buffer (file_buf) to a line buffer
until it encounters a newline character (\n). It copies characters one by one
until it reaches the newline or the end of the buffer.
*/
int	ft_len_to_newline(char *file_buf)
{
	int	i;
	int	len;

	if (file_buf == NULL)
		return (0);
	len = 0;
	i = 0;
	while (file_buf[i])
	{
		if (file_buf[i] == '\n')
		{
			len++;
			return (len);
		}
		i++;
		len++;
	}
	return (len);
}

/*
This function copies characters from a file buffer (file_buf) to a line buffer
until it encounters a newline character (\n). It copies characters one by one
until it reaches the newline or the end of the buffer.
*/
void	ft_copy_line(char *file_buf, char *line)
{
	int	i;
	int	j;

	if (file_buf == NULL)
		return ;
	j = 0;
	i = 0;
	while (file_buf[i])
	{
		if (file_buf[i] == '\n')
		{
			line[j++] = '\n';
			line[j] = '\0';
			return ;
		}
		line[j++] = file_buf[i++];
	}
	line[j] = '\0';
}

/*
This function checks if there is a newline character (\n) in 
the file buffer (file_buf). It iterates through the buffer and 
returns 1 if it finds a newline, indicating the presence of the 
next line, otherwise returns 0.
*/
int	ft_find_nextline(char *file_buf)
{
	int	i;

	if (file_buf == NULL)
		return (0);
	i = 0;
	while (file_buf[i])
	{
		if (file_buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
This function appends a character buffer (buf) to a file buffer (file).
If the file buffer is empty, it initializes it with null termination. 
Then it dynamically allocates memory for a new string, copies the contents
of both buffers into it, and returns the new string.
*/
char	*ft_append_char_read(char *file, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!file)
	{
		file = malloc(sizeof(char));
		file[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(file) + ft_strlen(buf)) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (file[i])
	{
		str[i] = file[i];
		i++;
	}
	while (buf[j])
		str[i++] = buf[j++];
	str[i] = '\0';
	free(file);
	return (str);
}
