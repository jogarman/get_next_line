/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:20:28 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/09 19:04:56 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *get_next_line(int fd)
{
	char	*ptr_buffer;
	char	*ret = 0;

	ptr_buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (ptr_buffer == NULL)
		return (NULL);
	printf("%zd", read(fd, ptr_buffer, BUFFER_SIZE));

	return (ret);
}

#include <fcntl.h> // Para la función open y los flags como O_RDONLY
int	 main()
{
	int	fd;

	fd = open("./texto.txt", O_RDONLY);
	get_next_line(fd);
}