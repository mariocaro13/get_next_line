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

#include "../get_next_line_bonus.h"

void	ft_read_all(int fd)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = get_next_line(fd);
	while (buffer)
	{
		printf("Line %i: %s", i, buffer);
		i++;
		free(buffer);
		buffer = get_next_line(fd);
	}
}

void	ft_read_n_lines(int fd, int nb)
{
	int	i;

	i = 1;
	while (i <= nb)
	{
		printf("FD: %i, Line %i: %s\n", fd, i, get_next_line(fd));
		i++;
	}
}

int	main(void)
{
	int	fd;
	int	fd2;
	int	fd3;

	fd = open("files/si", O_RDONLY);
	fd2 = open("files/read_error.txt", O_RDONLY);
	fd3 = open("files/short_text", O_RDONLY);
	if (fd > 0)
		ft_read_n_lines(fd, 1);
	if (fd2 > 0)
		ft_read_n_lines(fd2, 1);
	if (fd3 > 0)
		ft_read_n_lines(fd3, 1);
	close(fd);
	return (0);
}
