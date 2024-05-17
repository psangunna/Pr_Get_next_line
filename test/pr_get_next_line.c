# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>

/*Size of buffer*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*functions*/
char	*get_next_line(int fd);
char	*ft_read_from_file(char *file_buf, int fd);
char	*ft_get_line(char *file_buf);
char	*ft_clean_file_buf(char *file_buf);
int		ft_find_nextline(char *file_buf);
char	*ft_append_char_read(char *file_buf, char *buf);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_len_to_newline(char *file_buf);
void	ft_copy_line(char *file_buf, char *line);


//int	main(int argc, char *argv[])
int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		lines;

	/*if (argc != 2)
	{
		printf("Uso: %s <nombre_archivo>\n", argv[0]);
		return (1);
	}*/
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	printf("BUFFER_SIZE:%i\n", BUFFER_SIZE);
	lines = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("buffer --> %i %s\n", lines++, line);
		free(line);
	}
	close(fd);
	return (0);
}


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
	while (file_buf[i] != '\0')
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
	static char		*file_buf;
	char			*show_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file_buf = ft_read_from_file(file_buf, fd);
	if (file_buf == NULL)
		return (NULL);
	show_line = ft_get_line(file_buf);
	file_buf = ft_clean_file_buf(file_buf);
	return (show_line);
}

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
Given a file buffer (file_buf), this function calculates the length 
from the beginning of the buffer to the first newline character (\n). 
It iterates through the buffer until it finds a newline character and 
returns the length including the newline.
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


