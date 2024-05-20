CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address 

BUFFER = $(if $(bsize),-D BUFFER_SIZE=$(bsize))

NAME = gnl

SOURCE = main.c \
	 ../get_next_line.c \
	 ../get_next_line_utils.c \

OBJECTS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	 $(CC) $(CFLAGS) $(BUFFER) $(OBJECTS) -o $(NAME)

run:	re
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
.PHONY: all clean fclean re run bsize valgrind
