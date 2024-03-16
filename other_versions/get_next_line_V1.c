/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linev1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:20:28 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/11 16:08:51 by jgarcia3         ###   ########.fr       */
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
	char		*A = NULL;
	static char	*B;

	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (buffer == NULL || fd >= OPEN_MAX)
		return (NULL);
	if (-1 == read(fd, buffer, BUFFER_SIZE)) // Proteccion de read
		return (NULL);
	while (ft_strchr_modified(buffer, '\n') == -1) // bucle hasta encontrar \n
	{
		if (B == NULL) //programa empieza aqui
		{
			B = malloc((BUFFER_SIZE + 1) * sizeof(char));
			B[0] = '\0';
		}
		B = ft_strjoin(B, buffer);
		read(fd, buffer, BUFFER_SIZE);
	}
	B = ft_strjoin(B, buffer);
	A = ft_strdup_l(B, ft_strchr_modified(B, '\n')); //pasa B a A hasta \n
	//Free B

	// Copiamos A desde \n a B


	return (A);
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
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
} */