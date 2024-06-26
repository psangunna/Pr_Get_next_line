/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:56:54 by psangunna         #+#    #+#             */
/*   Updated: 2024/05/16 18:56:57 by psangunna        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
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
int		ft_len_to_newline(char *file_buf);
void	ft_copy_line(char *file_buf, char *line);

#endif
