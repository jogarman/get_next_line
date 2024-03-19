/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:18:37 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/11 17:23:25 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif               //poner 1024

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //Borrar. Es para printf
# include <limits.h>

//utils
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup_l(const char *s1, unsigned int l);
int		ft_strchr_modified(const char *s, int c);
char	*ft_strchr(const char *s, int c);

#endif
