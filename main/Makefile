# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaro-ro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 12:07:35 by mcaro-ro          #+#    #+#              #
#    Updated: 2024/05/21 12:33:43 by mcaro-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address 

BUFFER = $(if $(bsize),-D BUFFER_SIZE=$(bsize))

NAME = gnl

SOURCE = main.c \
	 ../get_next_line.c \
	 ../get_next_line_utils.c \

SBONUS =  ../get_next_line_bonus.c \
	 ../get_next_line_utils_bonus.c \

OBJECTS = $(SOURCE:.c=.o)

BOBJECTS = $(SBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	 $(CC) -g $(CFLAGS) $(BUFFER) $(OBJECTS) -o $(NAME)

bonus: $(BOBJECTS)

$(BOBJECTS):
	$(CC) -g $(CFLAGS) $(BUFFER) $(BOBJECTS) -o $(NAME)

run: re
	@if [ "$(bsize)" ]; then \
		$(MAKE) fclean --silent; \
		$(MAKE) all CFLAGS="$(CFLAGS) -D BUFFER_SIZE=$(bsize)" --silent; \
	fi
	@./$(NAME)

valgrind:
	@valgrind ./$(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.DEFAULT_GOAL := all
.PHONY: all clean fclean re run bonus bsize valgrind
