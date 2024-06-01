#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define NEWLINE_CHAR '\n'
# define NULL_TERMINATE '\0'
# define NULL_TERMINATE_SIZE 1

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
 * In case the end of the list is NULL set the head of the list to the new node.
 *
 * @param list_head Pointer to the head node of the list (can be NULL).
 * @param content Char pointer with the content for the new node.
 */
void	ft_append_node(t_list **list_head, char *conten);

/**
 * Calculates the length of a line within the content of a linked list node.
 *
 * @param node Pointer to the current node (can be NULL).
 * @return Length of the line within the content.
 */
int		ft_get_linelen(t_list *node);

/**
 * Setts a str with the content of a linked list node untill a new line.
 *
 * @param node Pointer to the current node (can be NULL).
 * @param str Char pointer to the str to be setted.
 * @retrun If 'node' or 'str' is NULL, indicating an empty or non-existent list,
 *      returns immediately.
 */
void	ft_set_line(t_list *node, char *str);

/**
 * Searches a character in a list by starting by a given node.
 *
 * @param node Pointer to the input node (can be NULL).
 * @param c The character to search for.
 * @return 1 if the character is found in the string, 0 otherwise.
 */
int		ft_find_char_in_list(const t_list *node, const char c);

void	ft_free_list(t_list **list_head);
void	ft_set_content_cleaned(t_list **list_head, char *str);
void	ft_clean_list(t_list **list_head);
#endif
