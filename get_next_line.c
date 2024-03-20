/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:20:28 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/20 01:35:28 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* copia solo hasta el salto de linea */
char	*ft_strdup_mod(const char *s1) //1
{
	size_t	i;
	char	*str;

	i = 0;
	str = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	while (i < ft_strlen(s1) && s1[i] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		str[i] = '\n';
		str[i + 1] = '\0';
	}
	return (str);
}

/* Si existe el caracter devuelve el puntero || True */
char	*ft_strchr_mod(const char *s, int c) //2
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*load_until_br(char *previous_line, int fd) //3
{
	char	*buffer;
	int		error;

	error = 0;

	while (!ft_strchr_mod(previous_line, '\n')) //Si NO encuentra \n
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		error = read(fd, buffer, BUFFER_SIZE);
		if (error == -1)
			return (free(buffer), free(previous_line), NULL);
		previous_line = merge(previous_line, buffer);
		if (ft_strlen(previous_line) == 0)
			return (free(buffer), free(previous_line), buffer = NULL, NULL);
		if (ft_strlen(buffer) != BUFFER_SIZE)
			return (free(buffer), buffer = NULL, previous_line);
		free(buffer);
		buffer = NULL;
	}
	return (previous_line);
}

/*
	devuelve un puntero a un string que contiene s1 DESDE \n
	TIENE UN BUG. CUANDO BUFFER_SIZE = 5 Y UNA CADENA DE 200, NO DEVUELVE EL PUNTERO CORRECTAMENTE
*/
char	*new_previous_line(char *s1) //4
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s1[i] != '\n' && s1[i] != '\0') //si hay 0 liberar y retornar null
	{
		i++;
	}
	if (ft_strlen(s1) == (size_t)i)
		return(free(s1), NULL);
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

char	*get_next_line(int fd) //5
{
	char		*line;
	static char	*previous_line;

	if (fd >= OPEN_MAX || fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	// Si no hay salto de linea, cargará hasta encontrarlo
	previous_line = load_until_br(previous_line, fd);
	if (previous_line == NULL)
		return (free(previous_line), NULL);
	// Copia de previous_line a line solo hasta \n (incluido) + '\0'
	line = ft_strdup_mod(previous_line);
	if (line == NULL)
		return (NULL);
	// Copia de previous line a previous line desde después de '\n'.
	// Verificar si no hay \0
	previous_line = new_previous_line(previous_line);

	return (line);
}

void	leaks_cheker()
{
	system("leaks a.out");
}

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> // Para la función open y los flags como O_RDONLY
/* int	 main()
{
	char	*line = NULL;

	atexit(leaks_cheker);
	int	fd;
	int	i = 0;

	fd = open("./texto", O_RDONLY);
	while (i != 5000)
	{
		line = get_next_line(fd);
		printf("|---|%s", line);
		if (line == NULL)
			return (EXIT_SUCCESS);
		free(line);
		i++;
	}

	close(fd);
} */
/*
leaks:
- archivo vacio
-
 */

/* //Tester for new_previous_line
int    main()
{
    char    s0[] = "sdafaf";
    char    *s1 = NULL;

    s1 = strdup(s0);

    printf("%s", new_previous_line(s1));
} */