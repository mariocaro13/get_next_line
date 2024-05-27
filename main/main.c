/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:07:28 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/05/21 12:16:10 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../get_next_line.h"

void	ft_read_all(int fd)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		printf("Line %i: %s", i, get_next_line(fd));
		i++;
	}
	free(buffer);
}

void	ft_read_n_lines(int fd, int nb)
{
	int	i;

	i = 1;
	while (i <= nb)
	{
		printf("Line %i: %s", i, get_next_line(fd));
		i++;
	}
}

int	main(void)
{
	int		fd;

	fd = open("files/text", O_RDONLY);
	if (fd > 0)
		ft_read_n_lines(fd, 1);
	close(fd);
	return (0);
}
