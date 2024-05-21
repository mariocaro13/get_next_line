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

int	main(void)
{
	int	fd;
	int	i;

	fd = open("short_text.txt", O_RDONLY);
	if (fd > 0)
	{
		i = 1;
		while (i <= 4)
		{
			printf("Line %i: %s", i, get_next_line(fd));
			i++;
		}
	}
	close(fd);
	return (0);
}
