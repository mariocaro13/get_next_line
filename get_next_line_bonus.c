/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:53:59 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/07/01 14:55:43 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_append_node(t_list **list_head, char *content)
{
	t_list	*new_node;
	t_list	*last_node;

	if (!list_head)
		return ;
	last_node = ft_get_last_node(*list_head);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->next = NULL;
	if (!last_node)
		*list_head = new_node;
	else
		last_node->next = new_node;
}

void	ft_create_list(t_list **list, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	if (!list || fd < 0)
		return ;
	while (!ft_find_char_in_list(*list, NEWLINE_CHAR))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free (buffer);
			if (bytes_read < 0)
				ft_free_list(list);
			return ;
		}
		buffer[bytes_read] = NULL_TERMINATE;
		ft_append_node(list, buffer);
	}
}

int	ft_get_linelen(t_list *node)
{
	int	i;
	int	len;

	if (!node)
		return (0);
	len = 0;
	while (node)
	{
		i = 0;
		while (node->content[i])
		{
			if (node->content[i] == NEWLINE_CHAR)
			{
				len++;
				return (len);
			}
			len++;
			i++;
		}
		node = node->next;
	}
	return (len);
}

void	ft_set_line(t_list *node, char *str)
{
	int		i_content;
	int		i_str;

	if (!node || !str)
		return ;
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
				return ;
			}
			str[i_str++] = node->content[i_content++];
		}
		node = node->next;
	}
	str[i_str] = NULL_TERMINATE;
}

char	*get_next_line(int fd)
{
	static t_list	*list_head = NULL;
	char			*line;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	ft_create_list(&list_head, fd);
	if (!list_head)
		return (NULL);
	line = malloc(ft_get_linelen(list_head) + NULL_TERMINATE_SIZE);
	if (!line)
		return (NULL);
	ft_set_line(list_head, line);
	ft_clean_list(&list_head);
	return (line);
}
