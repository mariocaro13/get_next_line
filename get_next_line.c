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

/**
 * Retrieves the last node of a linked list.
 * Iterates each node of the linked list starting from the head
 * pointed by 'list'.Is follows the 'next' pointers
 * of each node until it reaches the last node, identified by'next' pointer being NULL. 
 *
 * @param list A double pointer to the first node of the linked list.
 *
 * @return The last node of the list if the list is not empty; otherwise, NULL.
 * 	If the 'list' pointer is NULL, indicating an empty or non-existent list,
 * 	returns NULL immediately.
 */
t_list	*ft_get_last_node(t_list **list)
{
	t_list *node;

	if (!list)
		return (NULL);
	node = *list;
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

//Create a new node and add it to the last ocurrence of the list.
//	The new node will be setted as:
//		Content = char *'content'
//		Next = 'NULL'
//In case the content of the last node if null set it to str: 'content'
void	ft_append_node(t_list *last, char *content)
{
	t_list	*new_node;

	if (last->content == NULL && last)
		last->content = content;
	else
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			free(new_node);
			return ;
		}
		last->next = new_node;
		new_node->content = content;
		new_node->next = NULL;
	}
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
	if (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		printf("Create list:\n");	
		printf("Last Node: %p\n", ft_get_last_node(list));
		printf("Last Content: %s\n\n", ft_get_last_node(list)->content);
		ft_append_node(ft_get_last_node(list), buffer);
		printf("Append: \n");
		printf("Last Node: %p\n", ft_get_last_node(list));
		printf("Last Content: %s\n\n", ft_get_last_node(list)->content);
	}
	if (!find_char(buffer, '\n'))
		ft_create_list(list, fd);
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
	ft_create_list(&list, fd);
	if (!list)
		return (NULL);
	
	//Fetch line from list
	line = ft_get_line(list);
	printf("Line: %s", line);
	//Clean list
//	ft_clean_list(&list);
	return (line);
}
