/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:06:55 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/05/21 12:46:51 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_char(const char *str, const char c)
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

t_list	*ft_get_last_node(t_list *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

char	*ft_iterate_str_to_newline(char *str)
{
	if (!str)
		return (NULL);
	while (*str != '\0' && *str != '\n')
		str++;
	if (*str == '\n')
		return (str + 1);
	return (NULL);
}

void	ft_clean_list(t_list **list)
{
	t_list	*current_node;
	t_list	*new_head;
	char	*str;

	if (!list || !*list)
		return ;
	str = ft_iterate_str_to_newline(ft_get_last_node(*list)->content);
	while (*list)
	{
		current_node = *list;
		*list = current_node->next;
//		free(current_node->content);
		free(current_node);
	}
	new_head = malloc(sizeof(t_list));
	if (!new_head)
		return ;
	new_head->content = str;
	new_head->next = NULL;
	*list = new_head;
}
