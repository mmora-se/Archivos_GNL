/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                          :+:      :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: mmora-se <mmora-se@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:01:48 by mmora-se          #+#    #+#             */
/*   Updated: 2021/04/21 11:54:37 by mmora-se         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include  " get_next_line.h "
# incluye  < fcntl.h >
# incluye  < stdio.h >

/ * main para probar múltiples fds llamando a gnl en las primeras 3 líneas de cada archivo * /
int 		main ( int argc, char ** argv)
{
	int fd;
 	int fd2;
	char * línea;
	int ret; / * imprimiendo el valor de retorno gnl * /
	int i;

	si (argc> = 2 )
	{
		si ( acceso (argv [ 1 ], F_OK) == 0 )
		{
			fd = abierto (argv [ 1 ], O_RDONLY);
			fd2 = abierto (argv [ 2 ], O_RDONLY);
			ret = get_next_line (fd, & línea);
			si (ret == 1 )
				printf ( " PRINCIPAL: % d , línea1> % s \ n " , ret, línea);
			ret = get_next_line (fd2, & línea);
			si (ret == 1 )
				printf ( " PRINCIPAL: % d , línea1> % s \ n " , ret, línea);
			ret = get_next_line (fd, & línea);
			si (ret == 1 )
				printf ( " PRINCIPAL: % d , línea2> % s \ n " , ret, línea);
			ret = get_next_line (fd2, & línea);
			si (ret == 1 )
				printf ( " PRINCIPAL: % d , línea2> % s \ n " , ret, línea);
			ret = get_next_line (fd, & línea);
			si (ret == 1 )
				printf ( " PRINCIPAL: % d , línea3> % s \ n " , ret, línea);
			ret = get_next_line (fd2, & línea);
			si (ret == 1 )
				printf ( " PRINCIPAL: % d , línea3> % s \ n " , ret, línea);
			cerrar (fd);
			cerrar (fd2);
		}
	}
	volver ( 1 );
}