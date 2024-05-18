# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../get_next_line.h"



int	main(void)
{
	int	fd;
	int	i;

	fd = open("short_text.txt", O_RDONLY);
	if (fd > 0)
	{
		i = 0;
		while (i < 1)
		{
			printf("Line %i: %s\n", i++, get_next_line(fd));
		}
	}
	close(fd);
	return (0);
}
