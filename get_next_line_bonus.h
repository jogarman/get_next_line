/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:18:37 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/20 12:59:02 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //Borrar. Es para printf
# include <limits.h>

//principal
char	*ft_strdup_len_prev_line(const char *s1, int len_prev_line);
char	*ft_strdup_mod(const char *s1);
char	*load_until_br(char *previous_line, int fd);
char	*new_previous_line(char *s1);
char	*get_next_line(int fd);

//utils
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr_mod(const char *s, int c);
char	*merge(char *s1, char *s2, int len_prev_line);
#endif
