#include "get_next_line.h"

int	find_char(const char *str, const char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && i < INT_MAX)
		i++;
	return (i);
}

//Create List create and sets buffers value in content and create a new NULL Node to the list
//
void	ft_create_list(t_list **list, int fd)
{
	char	*buffer;

	if (!list || !fd)
		return ;
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return ;
	}
	while (read(fd, buffer, BUFFER_SIZE) > 0 && !find_char(buffer, '\n'))
	{
		t_list	*new_node;
		t_list	*current_node;

		current_node = *list;
		if (current_node->content == NULL)
		{
			current_node->content = buffer;
			current_node->next = NULL;

			printf("New Node: %p\n", &new_node);
			printf("Current Node: %p\n", &current_node);
			printf("Current Content: %s\n", current_node->content);
			printf("Buffer: %s\n", buffer);
			printf("Current Next: %p\n", current_node->next);
			printf("*List: %p\n\n", *list);
		}
		else
		{
			new_node = malloc(sizeof(t_list));
			if (!new_node)
			{
				free (buffer);
				return ;
			}
			new_node->content = buffer;
			new_node->next = NULL;

			printf("New Node: %p\n", &new_node);
			printf("Current Node: %p\n", &current_node);
			printf("Current Content: %s\n", current_node->content);
			printf("Buffer: %s\n", buffer);
			printf("Current Next: %p\n", current_node->next);
			printf("*List: %p\n\n", *list);
			current_node->next = new_node;

			printf("New Node: %p\n", &new_node);
			printf("Current Node: %p\n", &current_node);
			printf("Current Content: %s\n", current_node->content);
			printf("Buffer: %s\n", buffer);
			printf("Current Next: %p\n", current_node->next);
			printf("*List: %p\n\n", *list);
			list = &(new_node);

			printf("New Node: %p\n", &new_node);
			printf("New Content: %s\n", new_node->content);
			printf("Buffer: %s\n", buffer);
			printf("New Next: %p\n", new_node->next);
			printf("*List: %p\n\n", *list);
	
		}
	}
	free (buffer);
}

char	*ft_get_line(t_list *list)
{
	char	*str;
	int	str_len;
	t_list	*aux_list;
	int	i_str;
	int	i_content;

	if (!list)
		return (NULL);
	str_len = 0;
	aux_list = list;
	while (!find_char(list->content, '\n') && list)
	{
		str_len += ft_get_strlen(list->content);
		list = list->next;
	}
	str = malloc(str_len + 1 * sizeof(char));
	if (!str)
	{
		//free(str);
		return (NULL);
	}
	list = aux_list;
	i_str = 0;
	i_content = 0;
	while (list->content[i_content] != '\n' && list)
	{
		str[i_str++] = list->content[i_content++];
		if (i_content > BUFFER_SIZE || list->content[i_content] == '\0')
		{
			list = list->next;
			i_content = 0;
		}
	}
	str[i_str] = '\0';
	return (str);
}

// Get Next Line function (description)
//
//
//
char	*get_next_line(int fd)
{
	static t_list	*list;
	char	*line;

	if (!fd || fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);

	line = NULL;
	list = malloc(sizeof(t_list));
	printf("List: %p\n", list);
	printf("Content: %s\n\n", list->content);
	ft_create_list(&list, fd);
	if (!list)
		return (NULL);
	
	//Fetch line from list
//	line = ft_get_line(list);
//	printf("Line: %s", line);
	//Clean list
//	ft_clean_list(&list);
	return (line);
}
