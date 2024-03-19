/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:20:28 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/18 19:17:36 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*load_until_br(char *previous_line, int fd)
{
	char	*buffer;
	int		error;

	error = 0;
	while (ft_strchr_mod(previous_line, '\n') == -1) //Si NO encuentra \n
	{
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buffer)
			return (NULL);
		error = read(fd, buffer, BUFFER_SIZE);
		if (error == -1)
			return (free(buffer), free(previous_line), NULL);
/* 		if (error == 0)
			return (free(buffer), buffer = NULL, NULL); */
		previous_line = merge(previous_line, buffer);
		if (error < (int)BUFFER_SIZE) //si lee menos del tamaño del buffer devueve error. Podria no
			{						//funcionar por si el tamaño del buffer es múltiplo del
				free(buffer);		//numero de caracteres que quiero leer
				buffer = NULL;
				return (previous_line);
			}
		free(buffer);
		buffer = NULL;
	}
	return (previous_line);
}

/*
	devuelve un puntero a un string que contiene s1 DESDE \n
*/
char	*new_previous_line(char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s1[i] != '\n' && s1[i] != '\0') //si hay 0 liberar y retornar null
	{
		i++;
	}
	if (i == 0)
		return (free(s1), NULL);
	str = ft_calloc((ft_strlen(s1) - i) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i++;
	j = 0;
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*previous_line;

	if (fd >= OPEN_MAX || fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	// si no hay salto de linea, cargará hasta encontrarlo
	previous_line = load_until_br(previous_line, fd);
	if (previous_line == NULL)
		return (NULL);
	//Copia de previous_line a line solo hasta \n (incluido) + '\0'
	line = ft_strdup_mod(previous_line);
	if (line == NULL)
		return (NULL);
	//Copia de previous line a previous line desde después de '\n'.
	//verificar si no hay \0
	previous_line = new_previous_line(previous_line);
	if (previous_line == NULL)
		return (NULL);
	return (line);
}

/* void	leaks_cheker()
{
	system("leaks a.out");
}

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> // Para la función open y los flags como O_RDONLY
int	 main()
{
	char	*line = NULL;

	atexit(leaks_cheker);
	int	fd;
	int	i = 0;

	fd = open("./texto", O_RDONLY);
	while (i != 100)
	{
		line = get_next_line(fd);
		printf("---%s", line);
		if (line == NULL)
			return (EXIT_SUCCESS);
		free(line);
		i++;
	}

	close(fd);
} */