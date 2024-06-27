/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:33:20 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/18 12:33:35 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*list_head[100];
	char			*line;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (!ft_create_list(&list_head[fd], fd))
		return (NULL);
	if (!list_head[fd])
		return (NULL);
	line = malloc(ft_get_linelen(list_head[fd]) + NULL_TERMINATE_SIZE);
	if (!line)
		return (NULL);
	if (!ft_set_line(list_head[fd], line))
		return (NULL);
	if (!ft_clean_list(&list_head[fd]))
		return (NULL);
	return (line);
}

int	ft_create_list(t_list *list_head[], int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	if (!list_head[fd] || fd < 0)
		return (1);
	while (!ft_find_char_in_list(list_head[fd], NEWLINE_CHAR))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free (buffer);
			if (bytes_read < 0)
				return (ft_free_list(list_head), 0);
		}
		buffer[bytes_read] = NULL_TERMINATE;
		if (!ft_append_node(list_head, buffer))
			return (1);
	}
	return (0);
}

int	ft_get_linelen(t_list *node)
{
	int	i;
	int	len;

	len = 0;
	if (!node)
		return (len);
	while (node)
	{
		i = 0;
		while (node->content[i])
		{
			if (node->content[i++] == NEWLINE_CHAR)
				return (++len);
			len++;
		}
		node = node->next;
	}
	return (len);
}

int	ft_set_line(t_list *node, char *str)
{
	int	i_content;
	int	i_str;

	if (!node || !str)
		return (1);
	i_str = 0;
	while (node)
	{
		i_content = 0;
		while (node->content[i_content])
		{
			if (node->content[i_content] == NEWLINE_CHAR)
			{
				str[i_str++] = NEWLINE_CHAR;
				str[i_str] = NULL_TERMINATE;
				return (0);
			}
			str[i_str++] = node->content[i_content++];
		}
		node = node->next;
	}
	str[i_str] = NULL_TERMINATE;
	return (0);
}

void	ft_free_list(t_list **list_head)
{
	t_list	*aux;

	if (!list_head)
		return ;
	while (*list_head)
	{
		aux = (*list_head)->next;
		free((*list_head)->content);
		free(*list_head);
		*list_head = aux;
	}
	*list_head = NULL;
}
