#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		free(node);
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	return (node);
}

char	*get_next_line(int fd)
{
	t_list	*node;
	char	*str = NULL;
	char	*buffer;
	int	bytes_read;
	int	i;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		node = ft_lstnew(buffer);
		if (!node)
		{
			free(node);
			return (NULL);
		}
		i = 0;
		while (node->content[i] != '\n' && i <= bytes_read)
		{
			str[i] = node->content[i];
			i++;
		}
		str[i] = '\0';

	}
	return (str);
}
