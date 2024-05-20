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

t_list	*ft_get_last_node(t_list **list)
{
	t_list	*node;

	if (!list)
		return (NULL);
	node = *list;
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}
