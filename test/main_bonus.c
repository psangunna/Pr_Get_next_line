/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:06:44 by psangunna         #+#    #+#             */
/*   Updated: 2024/05/16 19:06:52 by psangunna        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;
	int		fin;

	if (argc != 4)
	{
		printf("Uso: %s <archivo1> <archivo2> <archivo3>\n", argv[0]);
		return (1);
	}
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		perror("Error al abrir el archivo 1");
		return (1);
	}
	fd2 = open(argv[2], O_RDONLY);
	if (fd2 == -1)
	{
		perror("Error al abrir el archivo 2");
		close(fd1);
		return (1);
	}
	fd3 = open(argv[3], O_RDONLY);
	if (fd3 == -1)
	{
		perror("Error al abrir el archivo 3");
		close(fd1);
		close(fd2);
		return (1);
	}
	fin = 0;
	while (fin < 3)
	{
		line = get_next_line(fd1);
		if (line != NULL)
		{
			printf("Archivo 1: %s\n", line);
			free(line);
		}
		else
		{
			fin++;
		}
		line = get_next_line(fd2);
		if (line != NULL)
		{
			printf("Archivo 2: %s\n", line);
			free(line);
		}
		else
		{
			fin++;
		}
		line = get_next_line(fd3);
		if (line != NULL)
		{
			printf("Archivo 3: %s\n", line);
			free(line);
		}
		else
		{
			fin++;
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
