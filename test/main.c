/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:55:15 by psangunna         #+#    #+#             */
/*   Updated: 2024/05/17 16:04:49 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		lines;

	if (argc != 2)
	{
		printf("Uso: %s <nombre_archivo>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	printf("BUFFER_SIZE:%i\n",BUFFER_SIZE);
	lines = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("buffer --> %i %s\n", lines++, line);
		free(line);
	}
	close(fd);
	return (0);
}
