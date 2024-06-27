/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:33:41 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/18 12:33:48 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_find_char_in_list(const t_list *node, const char c)
{
	int	i;

	if (!node)
		return (0);
	while (node)
	{
		i = 0;
		while (node->content[i] && i < INT_MAX)
		{
			if (node->content[i] == c)
				return (1);
			i++;
		}
		node = node->next;
	}
	return (0);
}

int	ft_append_node(t_list **list_head, char *content)
{
	t_list	*new_node;
	t_list	*last_node;

	if (!list_head)
		return (1);
	last_node = ft_get_last_node(*list_head);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (1);
	new_node->content = content;
	new_node->next = NULL;
	if (!last_node)
		*list_head = new_node;
	else
		last_node->next = new_node;
	return (0);
}

t_list	*ft_get_last_node(t_list *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

int	ft_clean_list(t_list **list_head)
{
	t_list	*new_head;
	char	*str;

	if (!list_head)
		return (1);
	str = malloc(BUFFER_SIZE + NULL_TERMINATE_SIZE);
	if (!str)
		return (1);
	new_head = malloc(sizeof(t_list));
	if (!new_head)
		return (free(str), 1);
	ft_set_content_cleaned(list_head, str);
	new_head->content = str;
	new_head->next = NULL;
	ft_free_list(list_head);
	if (*(new_head->content) == '\0')
		return (free(str), free(new_head), 0);
	*list_head = new_head;
	return (0);
}

void	ft_set_content_cleaned(t_list **list_head, char *str)
{
	t_list	*last_node;
	int		i_c;
	int		i_str;

	last_node = ft_get_last_node(*list_head);
	i_c = 0;
	while (last_node->content[i_c] != NEWLINE_CHAR && last_node->content[i_c])
		i_c++;
	i_str = 0;
	while (last_node->content[i_c] && last_node->content[i_c + 1])
		str[i_str++] = last_node->content[++i_c];
	str[i_str] = NULL_TERMINATE;
}
