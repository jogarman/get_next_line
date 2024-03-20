/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:20:28 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/20 15:18:51 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* copy until line break */
char	*ft_strdup_mod(const char *s1)
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

/* If char exist returns pointer to character */
char	*ft_strchr_mod(const char *s, int c)
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

char	*load_until_br(char *previous_line, int fd)
{
	char	*buffer;
	int		error;
	int		len_prev_line;

	while (!ft_strchr_mod(previous_line, '\n'))
	{
		if (previous_line)
			len_prev_line = ft_strlen(previous_line);
		else
			len_prev_line = 0;
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		error = read(fd, buffer, BUFFER_SIZE);
		if (error == -1)
			return (free(buffer), free(previous_line), NULL);
		previous_line = merge(previous_line, buffer, len_prev_line);
		if (ft_strlen(previous_line) == 0)
			return (free(buffer), free(previous_line), buffer = NULL, NULL);
		if (ft_strlen(buffer) != BUFFER_SIZE)
			return (free(buffer), buffer = NULL, previous_line);
		free(buffer);
	}
	return (previous_line);
}

/*
	Returns a pointer to an string that contains s1 from \n
	Its like copying the right side of the string
*/
char	*new_previous_line(char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
	{
		i++;
	}
	if (ft_strlen(s1) == (size_t)i)
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
	previous_line = load_until_br(previous_line, fd);
	if (previous_line == NULL)
		return (NULL);
	line = ft_strdup_mod(previous_line);
	if (line == NULL)
		return (NULL);
	previous_line = new_previous_line(previous_line);
	return (line);
}

/*

void	leaks_cheker()
{
	system("leaks a.out");
}

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> //  Open and O_RDONLY
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>
int	 main()
{
	char	*line = NULL;

	//atexit(leaks_cheker);
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
	70k characters in 12,2 s
	80k characters in 15,6 s
*/