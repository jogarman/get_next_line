/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_V2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:20:28 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/11 21:43:54 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
read devuelve el numero de bytes leidos. Si lee menos del tamaño del buffer
es que ha terminado.
-1 si da error
*/

/* char *get_next_line(int fd)
{
	char		*buffer;
	static char	*A = 0;
	char		*B;

	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (buffer == NULL || fd >= OPEN_MAX)
		return (NULL);
	if (-1 == read(fd, buffer, BUFFER_SIZE)) // Proteccion de read
		return (NULL);
	if (A == NULL)
		A = ft_strdup_l(buffer, BUFFER_SIZE + 1); //Si A es NULL lo crea y A = buffer
	while (ft_strchr_modified(A, '\n') == -1 && ft_strchr_modified(buffer, '\n') == -1) 		// si \n NO existe en A
	{
		read(fd, buffer, BUFFER_SIZE);
		B = ft_strdup_l(A, ft_strlen(A));								// A -> B
		A = malloc((ft_strlen(B) + BUFFER_SIZE + 1) * sizeof(char));	// nuevo A más grande
		A = ft_strjoin(B, buffer);									 // B -> A
		buffer[0] = '\0';
	}
	B= ft_strjoin(A, buffer); //Copio A + buffer a B hasta \n
	B[ft_strchr_modified(B, '\n')] = '\0';
	free(buffer);
	A = ft_strchr(A, '\n') + 1;
	return (B);
}

#include <fcntl.h> // Para la función open y los flags como O_RDONLY
int	 main()
{
	int	fd;

	fd = open("./texto.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
} */