#include "get_next_line.h"

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

void	ft_create_list(t_list **list, int fd)
{
	char	*buffer;

	if (!list || fd < 0)
		return ;
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return ;
	}
	if (read(fd, buffer, BUFFER_SIZE) > 0)
		ft_append_node(ft_get_last_node(list), buffer);
	if (!find_char(buffer, '\n'))
		ft_create_list(list, fd);
}

int	ft_get_linelen(t_list *node, int len)
{
	int	i;

	if (!node)
		return (len);
	i = 0;
	while (node->content[i] != '\n')
	{
		len ++;
		i++;
		if (node->content[i] == '\0')
			return (ft_get_linelen(node->next, len));
	}
	return (len);
}

char	*ft_get_line(t_list *node)
{
	int		str_len;
	int		i_content;
	int		i_str;
	char	*str;

	if (!node)
		return (NULL);
	str_len = ft_get_linelen(node, 0);
	str = malloc(str_len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	i_content = 0;
	i_str = 0;
	while (node->content[i_content] != '\n' && node)
	{
		str[i_str++] = node->content[i_content++];
		if (node->content[i_content] == '\0')
		{
			node = node->next;
			i_content = 0;
		}
	}
	str[i_str] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;

	if (!fd || fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	list = malloc(sizeof(t_list));
	ft_create_list(&list, fd);
	if (!list)
		return (NULL);
	line = ft_get_line(list);
//	ft_clean_list(&list);
	return (line);
}
