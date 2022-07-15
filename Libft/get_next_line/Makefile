# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 17:13:17 by Cerdelen          #+#    #+#              #
#    Updated: 2022/07/13 14:15:30 by cerdelen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wextra -Wall -Werror

AR = ar rcs

NAME = get_next_line.a

SRCS = 	get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: 
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=42 -c $(SRCS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\033[92mGNL with Buffersize of 42 successfully compiled!\033[0m"

5:
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=5 -c $(SRCS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\033[92mGNL with Buffersize of 5 successfully compiled!\033[0m"

10:
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=10 -c $(SRCS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\033[92mGNL with Buffersize of 10 successfully compiled!\033[0m"

25:
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=25 -c $(SRCS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\033[92mGNL with Buffersize of 25 successfully compiled!\033[0m"

50:
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=50 -c $(SRCS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\033[92mGNL with Buffersize of 50 successfully compiled!\033[0m"

100:
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=100 -c $(SRCS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\033[92mGNL with Buffersize of 100 successfully compiled!\033[0m"

250:
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=250 -c $(SRCS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\033[92mGNL with Buffersize of 250 successfully compiled!\033[0m"

500:
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=500 -c $(SRCS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\033[92mGNL with Buffersize of 500 successfully compiled!\033[0m"

1000:
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=1000 -c $(SRCS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\033[92mGNL with Buffersize of 1000 successfully compiled!\033[0m"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[91mGNL successfully cleaned!\033[0m"

re: fclean all
