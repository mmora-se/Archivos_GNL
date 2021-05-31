/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmora-se <mmora-se@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:58:55 by mmora-se          #+#    #+#             */
/*   Updated: 2021/05/30 12:17:19 by mmora-se         ###   ########.fr       */
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

	/* 1  gnl(1000, -1, NULL); void gnl(int fd, int r, char const * s);
	 2  gnl(-1, -1, NULL); */
	fd = 1000;
	line = NULL;
	retorno = get_next_line(fd, &line);
	printf("línea = %s\n return gnl = %d\n", line, retorno);
	free(line);
	//system("leaks a.out");
}
