/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmora-se <mmora-se@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:39:44 by mmora-se          #+#    #+#             */
/*   Updated: 2021/05/22 18:26:46 by mmora-se         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	************************************************************************* */
/*	ft_strlen: número de caracteres que preceden al carácter NULL '\0' final  */
/*  ************************************************************************* */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*	************************************************************************* */
/*	ft_strchr: devuelve puntero a la primera aparición del char c en cadena s */
/*	          Si c = '\0' => devuelve puntero al final de cadena              */
/*            Si c aparece en s => devuelve un puntero al primer c localizado */
/*            Si c NO aparece en s => devuelve NULL                           */
/*  ************************************************************************* */
char	*ft_strchr(const char *s, int c)
{
	char	*ps;

	ps = (char *)s;
	while (*ps != '\0')
	{
		if (*ps == (char)c)
			return (ps);
		ps++;
	}
	if (c == '\0')
		return (ps);
	return (0);
}

/*	************************************************************************* */
/*	ft_strjoin: Reserva memoria con malloc y devuelve la nueva cadena de      */
/*	            caracteres que resulta de la concatenación de s1 y s2         */
/*              Y NULL si falla la reserva de memoria                         */
/*  ************************************************************************* */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len_s1;
	size_t	len_s2;
	size_t	j;

	if ((s1 == NULL) || (s2 == NULL))
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * ((len_s1 + len_s2) + 1));
	if (p == 0)
		return (0);
	j = 0;
	while (*s1 != '\0')
		p[j++] = *s1++;
	while (*s2 != '\0')
		p[j++] = *s2++;
	p[j] = '\0';
	return (p);
}

/*	************************************************************************* */
/*	ft_strdup: Hace la copia y devuelve un puntero a la copia                 */
/*             Asigna suficiente memoria para una copia de la cadena 		  */
/*             Si no hay suficiente memoria disponible, se devuelve NULL      */
/*  ************************************************************************* */
char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*	************************************************************************* */
/*	ft_strcdup: Hace copia hasta que encuentra el carácter c, sin incluirlo   */
/*              si no lo encuentra hace copia de la cadena entera             */
/*             Asigna suficiente memoria para una copia de ese trozo la cadena*/
/*             Si no hay suficiente memoria disponible, se devuelve NULL      */
/*  ************************************************************************* */
char	*ft_strcdup(const char *s, int c)
{
	char	*p;
	size_t	i;

	i = 0;
	while ((s[i] != (char)c) && (s[i] != '\0'))
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (p == 0)
		return (0);
	p[i] = '\0';
	while (i-- > 0)
		p[i] = s[i];
	return (p);
}
