/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:07:15 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/05/21 12:11:08 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
////#include <stdio.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}		t_list;

/**
 * Reads a line ending with a newline character ('\n') from a file descriptor.
 * The caller is responsible for freeing the allocated memory.
 *
 * @param fd File descriptor to read from.
 * @return Pointer to the extracted line (allocated using malloc),
 * 	or NULL if an error occurs.
 **/
char	*get_next_line(int fd);

/**
 * Return the last node of a linked list.
 * Iterates each node of the linked list starting from the node
 * pointed by 'node'. Is follows the 'next' pointers
 * of each node until it reaches the last node,
 * identified by'next' pointer being NULL.
 *
 * @param list Pointer to the first node to start iterate.
 *
 * @return The last node of the list if the list is not empty; otherwise, NULL.
 *      If the 'node' pointer is NULL, indicating an empty or non-existent list,
 *      returns NULL immediately.
 */
t_list	*ft_get_last_node(t_list *node);

/**
 * Creates a list untill find a ('\n') in 'buffer'.
 *
 * @param list Pointer to the pointer of the list (can be NULL).
 * @param fd File descriptor for reading.
 */
void	ft_create_list(t_list **list, int fd);

/**
 * Adds a new node to the end of the list.
 *
 * @param last Pointer to the last node in the list (can be NULL).
 * @param content Char pointer with the content for the new node.
 */
void	ft_append_node(t_list *last, char *conten);

/**
 * Calculates the length of a line within the content of a linked list node.
 *
 * @param node Pointer to the current node (can be NULL).
 * @param len Int of the current accumulated length (initially 0).
 * @return Length of the line within the content.
 */
int		ft_get_linelen(t_list *node, int len);

/**
 * Extracts a line from the content of a linked list node.
 *
 * @param node Pointer to the current node (can be NULL).
 * @return Pointer to the extracted line (allocated using malloc),
 *  or NULL if node is NULL.
 *         The caller is responsible for freeing the allocated memory.
 */
char	*ft_get_line(t_list *node);

/**
 * Searches a character in a given string.
 *
 * @param str Pointer to the input string (can be NULL).
 * @param c The character to search for.
 * @return 1 if the character is found in the string, 0 otherwise.
 */
int		ft_find_char(const char *str, const char c);

/**
 * Calculates the length of a null-terminated string.
 *
 * @param str Pointer to the input string (can be NULL).
 * @return Length of the string (number of characters), or 0 if str is NULL.
 */
int		ft_get_strlen(char *str);

char	*ft_iterate_str_to_newline(char *str);
void	ft_clean_list(t_list **list);
#endif
