/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:21:46 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/19 20:47:42 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	Toma s1 y s2, y retorna s1 + s2 en s1 controlando leaks
*/


char	*merge(char *s1, char *s2)
{
	char	*temp;
	int		i;
	int		j;

	if (s1 == NULL)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	temp = ft_strdup(s1);
	free(s1);
	s1 = malloc((ft_strlen(temp) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s1)
		return (NULL);
	i = -1;
	while (temp[++i])
		s1[i] = temp[i];
	j = 0;
	while (s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	free(temp);
	return (s1);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*pointer;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	pointer = malloc(size * count);
	i = 0;
	if (pointer == 0)
		return (NULL);
	while (i < count * size)
	{
		pointer[i] = 0;
		i++;
	}
	return ((void *)pointer);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	i = 0;
	str = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}



/* int main()
{
	if(!ft_strchr_mod("hola", 'a') && !ft_strchr_mod("hola", 'w'))
	{
		printf("se imprime");
	}
	else
		printf("no se imprime");
	//printf("%s", ft_strchr_mod("hola", '\n'));
} */

/* int main()
{
	printf("\n%s\n", ft_strdup_mod("hola\n"));
} */
/* int main()
{
	printf("\n%s\n", ft_strdup(""));
} */