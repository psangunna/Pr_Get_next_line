# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 18:53:27 by psangunna         #+#    #+#              #
#    Updated: 2024/05/16 18:53:39 by psangunna        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line.c get_next_line_utils.c main.c
SRCS_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c
NAME = program
NAME_BONUS = program_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=42

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(NAME) $(NAME_BONUS)

.PHONY: all bonus clean
