/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:20:28 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/11 22:27:27 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
read devuelve el numero de bytes leidos. Si lee menos del tamaño del buffer
es que ha terminado.
-1 si da error
*/

/*
	copia de una cadena a un puntero desde el caracter c
*/

char *get_next_line(int fd)
{
	char		*buffer;
	static char	*A = 0;
	char		*B;

	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (buffer == NULL || fd >= OPEN_MAX)
		return (NULL);
	if (-1 == read(fd, buffer, BUFFER_SIZE)) // Proteccion de read
		return (NULL);
	if (A)
		B = ft_strjoin(A, buffer);
	else
		B = ft_strdup_l(buffer, BUFFER_SIZE);
	while (ft_strchr_modified(B, '\n') == -1) 		// si \n NO existe en A
	{
		read(fd, buffer, BUFFER_SIZE);
		A = ft_strdup_l(B, ft_strlen(B));							// B -> A
		free(B);
		B = malloc((ft_strlen(A) + BUFFER_SIZE + 1 )* sizeof(char));	//nuevo B más grande
		B = ft_strjoin(A, buffer);									 // B -> A
	}
	A[0] = '\0';
	//////////// A  debe tener espacio suficiente para recibir a la cadena B
	ft_strlcpy(A, B + ft_strchr_modified(B, '\n'),(ft_strlen(B) - ft_strchr_modified(B, '\n'))); //copio B en A desde '\n' para guardarlo
	////////////
	B[ft_strchr_modified(B, '\n')] = '\0'; 								   //pongo '\0' tras \n en B para devolverlo
	return (B);			//deberia de hacer free (B) en el return para limpiar los leaks
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
}