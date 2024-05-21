# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaro-ro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 12:07:42 by mcaro-ro          #+#    #+#              #
#    Updated: 2024/05/21 12:07:43 by mcaro-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR = main

BSIZE_FLAG = $(if $(bsize),bsize=$(bsize))

all:
	$(MAKE) -C $(DIR) --silent

run:
	$(MAKE) -C $(DIR) run $(BSIZE_FLAG) --silent

valgrind:
	$(MAKE) -C $(DIR) valgrind --silent

clean:
	$(MAKE) -C $(DIR) clean --silent

fclean:	clean
	$(MAKE) -C $(DIR) fclean --silent

re: fclean all

.DEFAULT_GOAL := all

.PHONY: all clean fclean re run bsize valgrind
.SILENT:
