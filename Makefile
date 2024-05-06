DIR = main

BSIZE_FLAG = $(if $(bsize),bsize=$(bsize))

all:
	$(MAKE) -C $(DIR) --silent

run:
	$(MAKE) -C $(DIR) run $(BSIZE_FLAG) --silent

clean:
	$(MAKE) -C $(DIR) clean --silent

fclean:	clean
	$(MAKE) -C $(DIR) fclean --silent

re: fclean all

.DEFAULT_GOAL := all

.PHONY: all clean fclean re run bsize
.SILENT:
