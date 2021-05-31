/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                          :+:      :+:    */
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

/ * principal para probar 1 fd * /
int 		main ( int argc, char ** argv)
{
	int fd;
	char * línea;
	int ret; / * imprimiendo el valor de retorno gnl * /
	int i;

	si (argc> = 2 )
	{
		si ( acceso (argv [ 1 ], F_OK) == 0 )
		{
			i = 0 ;
			fd = abierto (argv [ 1 ], O_RDONLY);
			while ((ret = get_next_line (fd, & line)) == 1 )
			{
				i ++;
				printf ( " PRINCIPAL: % d , línea> % s \ n " , ret, línea);
			}
			cerrar (fd);
       	}
	}
	volver ( 1 );
}