/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:23:12 by casteria          #+#    #+#             */
/*   Updated: 2020/09/10 21:17:05 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define STD_OUTPUT_STREAM 1
# define STD_ERROR_STREAM 2
# define SYMBOL_NEW_LINE '\n'
# define TRUE 1
# define FALSE -1
# define ENDLINE_REACHED 1
# define ENDLINE_NOT_FOUND 0
# define EOF_REACHED 0
# define SUCCESS 1
# define ERROR -1
# define BUFFER_SIZE 1

int				get_next_line(int fd, char **line);
int				consists(const char *str, const char c);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *c);

#endif
