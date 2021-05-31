/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmora-se <mmora-se@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:58:55 by mmora-se          #+#    #+#             */
/*   Updated: 2021/05/30 14:27:58 by mmora-se         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 	fcntl.h para open y close 
	stdio.h para printf
*/

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		retorno;

	fd = open("text.txt", O_RDONLY);
	line = NULL;
	if (fd == -1)
		write(1, "Error opening the file!\n", 24);
	else
	{
		retorno = 1;
		while (retorno)
		{
			retorno = get_next_line(fd, &line);
			printf("línea = %s\n return gnl = %d\n", line, retorno);
			free(line);
			line = NULL;
		}
	}
	close(fd);
	free(line);
	line = NULL;
	system("leaks a.out");
}
