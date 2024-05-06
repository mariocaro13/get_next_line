#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	line = buffer;
	return (line);
}
