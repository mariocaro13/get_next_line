# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../get_next_line.h"

int	main(void)
{
	int	fd;
	char	*content = "";
	
	fd = open("text.txt", O_RDONLY);
	content = get_next_line(fd);
	printf("%s", content);
	close(fd);
	free(content);
	return (0);
}
