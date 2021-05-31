/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmora-se <mmora-se@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:38:25 by mmora-se          #+#    #+#             */
/*   Updated: 2021/05/31 18:16:11 by mmora-se         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	ft_line(char **line, char **p_lec);
int	ft_end(ssize_t	num_bytes, char **line, char **p_lec);

/*	************************************************************************* */
/*	get_next_line: devuelve una línea que se termina con un salto de línea    */
/*                 o la última línea                                          */
/*  Devuelve 1   : si lee una línea      								      */
/*  Devuelve 0   : se ha terminado la lectura			                      */
/*  Devuelve -1  : si ha ocurrido un error                                    */
/*  ************************************************************************* */
int	get_next_line(int fd, char **line)
{
	static char	*lectura;
	char		*paux;
	char		bloque[BUFFER_SIZE + 1];
	ssize_t		num_bytes;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, bloque, 0))
		return (-1);
	if (lectura == NULL)
		lectura = ft_strdup("");
	else if (ft_line(line, &lectura))
		return (1);
	num_bytes = read (fd, bloque, BUFFER_SIZE);
	while (num_bytes > 0)
	{
		bloque [num_bytes] = '\0';
		paux = lectura;
		lectura = ft_strjoin (lectura, bloque);
		free(paux);
		if (ft_line(line, &lectura))
			return (1);
		num_bytes = read (fd, bloque, BUFFER_SIZE);
	}
	if (ft_end(num_bytes, line, &lectura) < 0)
		return (-1);
	return (0);
}

/*	************************************************************************* */
/*	ft_line: Busca con ft_strchr, si hay '/n'(salto de línea)				  */
/*           en la var estática lectura 				                      */
/*  - Si NO hay: retorna 0                                       		      */
/*	- Si Sí hay: line: lo informa con la parte inicial anterior al '/n'       */
/*                     con ft_strcdup                                         */
/*               lectura: lo informa con la parte final posterior al '/n'     */
/*                         con ft_strdup                                      */
/*               retorna 1                                                    */
/*  ************************************************************************* */
int	ft_line(char **line, char **p_lec)
{
	char		*pos_n;
	char		*pos_l;

	pos_l = 0;
	pos_n = ft_strchr(*p_lec, '\n');
	if (pos_n != NULL)
	{
		*line = ft_strcdup(*p_lec, '\n');
		pos_l = *p_lec;
		*p_lec = ft_strdup(pos_n + 1);
		free(pos_l);
		return (1);
	}
	return (0);
}

/*	************************************************************************* */
/*	ft_end: trata la última lectura antes del fin de fichero                  */
/*          (cuando read <= 0 y ya NO hay '/n' en la var estática lectura)    */
/*          - Si (read < 0): retorna -1 porque la última lectura dió error    */
/*          - Si (read = 0): line = lectura = final del texto                 */
/*                           free de var estática lectura y le asigna NULL    */
/*                           retorna 0                                        */
/*  ************************************************************************* */
int	ft_end(ssize_t	num_bytes, char **line, char **p_lec)
{
	if (num_bytes < 0)
		return (-1);
	*line = ft_strdup(*p_lec);
	free(*p_lec);
	*p_lec = 0;
	return (0);
}
