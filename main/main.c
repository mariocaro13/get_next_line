# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../get_next_line.h"



int	main(void)
{
	int	fd;
       	static char	*buffer = NULL;
	struct s_list	*node;
	
	char	*str =  "Pato";
	printf("Str default: %s\n", str);

	fd = open("short_text.txt", O_RDONLY);
	if (fd > 0)
	{
		buffer = malloc(BUFFER_SIZE * sizeof(char));
		if (read(fd, buffer, BUFFER_SIZE) > 0)
		{
			//	Metodo para guardar una str en Node->content
			node = malloc(sizeof(t_list));
			if (node)
			{
				node->content = buffer;
				node->content[BUFFER_SIZE + 1] = '\0';
				node->next = NULL;
				printf("Node->content: %s\n", node->content);
			}
		}	
		free(buffer);
		free(node);
	}
	close(fd);
	return (0);
}
