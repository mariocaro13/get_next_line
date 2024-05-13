# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../get_next_line.h"

int	found_line(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int	set_strlen(t_list *list)
{
	int	str_len;
	struct s_list *aux;

	//Settear el len en 1 para '\0'
	str_len = 1;
	//iterarar la list hasta que en el content haya un \n
	while (!found_line(list->content))
	{
		//Sumarle todo el buffer size porque tiene que guardar todo lo leido
		str_len += BUFFER_SIZE;
		aux = malloc(sizeof(t_list));
		if (aux)
		{
			aux = list;
			list = aux->next;
		}
		free(aux);
	}
	int i = 0;
	while (list->content[i] != '\n')
		printf("i: %i\n", i++);
	str_len += i;
	return (str_len);
}

void	set_node(int fd, char *buffer, t_list *list)
{
	char	*str =  "Pato";
	printf("Str default: %s\n", str);

	struct s_list	*node;
	
	while (!found_line(buffer))
	{
		if (read(fd, buffer, BUFFER_SIZE) > 0)
		{
			node = malloc(sizeof(t_list));
			if (node)
			{
				if (list->content == NULL)
				{
					list->content = buffer;
					list->next = node;
					printf("LIST->content: %s\n", list->content);
				}
				else 
				{
					node->content = buffer;
					node->next = NULL;
					printf("Node->content: %s\n", node->content);
				}
			}
		}
	}	
}

int	main(void)
{
	int	fd;
	static char	*buffer = NULL;
	struct s_list	*list;
	char	*str;

	fd = open("short_text.txt", O_RDONLY);
	if (fd > 0)
	{
		buffer = malloc(BUFFER_SIZE * sizeof(char));
		list = malloc(sizeof(t_list));
		if (buffer && list)
		{
			set_node(fd, buffer, list);
			//printf("str_len: %i\n", set_strlen(list));
			int str_len = set_strlen(list);
			str = malloc(str_len * sizeof(char));
			if (str)
			{
				str[str_len] = '\0';
				int i = 0;
				while (!found_line(list->content))
				{	
					int i_c = 0;
					str[i] = list->content[i_c];
					if (!found_line(list->content) && i_c >= BUFFER_SIZE)
					{
						struct s_list *aux;
						aux = malloc(sizeof(t_list));
						if (aux)
						{
							aux = list;
							list = aux->next;
						}
						free(aux);
					}
				}
				printf("STR: %s\n", str);
			}
			free(str);
		}
		free(buffer);
	}
	close(fd);
	return (0);
}
