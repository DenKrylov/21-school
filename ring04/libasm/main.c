/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:22:09 by monie             #+#    #+#             */
/*   Updated: 2020/11/19 19:18:41 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

ssize_t			ft_write(int fd, const void *buf, int len);
ssize_t			ft_read(int fd, void *buf, int len);
unsigned long	ft_strlen(const char *str);
char			*ft_strcpy(char *dest, const char *src);
int				ft_strcmp(const char *str1, const char *str2);
char			*ft_strdup(const char *str);

int		fd;
char	s[] = ""; 
char	ss[] = "short string";
char	ss1[] = "short strinq";
char	sl[] = "long string long string long string long string long string long string long string long string long string long string long string long string long string long string long string long string";
char	se[192];
char	buff[400];
ssize_t	returns;

int main(void)
{
	printf("\n-------------------------------------------------------FT_STRLEN-------------------------------------------------------\n");
	printf("Try ft_strlen with an empty string\n");
	printf("S - %lu\n", strlen(s));
	printf("A - %lu\n", ft_strlen(s));
	printf("Try ft_strlen with a very short string\n");
	printf("S - %lu\n", strlen(ss));
	printf("A - %lu\n", ft_strlen(ss));
	printf("Try ft_strlen with a very long string\n");
	printf("S - %lu\n", strlen(sl));
	printf("A - %lu\n", ft_strlen(sl));	
	printf("\n-------------------------------------------------------FT_STRCPY-------------------------------------------------------\n");
	bzero(se, 192);
	printf("Try ft_strcpy with an empty string\n");
	printf("S - %s\n", strcpy(se, s));
	bzero(se, 192);
	printf("A - %s\n", ft_strcpy(se, s));
	bzero(se, 192);
	printf("Try ft_strcpy with a very short string\n");
	printf("S - %s\n", strcpy(se,ss));
	bzero(se, 192);
	printf("A - %s\n", ft_strcpy(se, ss));
	bzero(se, 192);
	printf("Try ft_strcpy with a very long string\n");
	printf("S - %s\n", strcpy(se, sl));
	bzero(se, 192);
	printf("A - %s\n", ft_strcpy(se, sl));
	printf("\n-------------------------------------------------------FT_STRCMP-------------------------------------------------------\n");
	printf("Try ft_strcmp with 2 empty strings\n");
	printf("S ---- strcmp: %d\n", strcmp(s, s));
	printf("A - ft_strcmp: %d\n", ft_strcmp(s, s));
	printf("Try ft_strcmp with 1 empty string as first argument\n");
	printf("S ---- strcmp: %d\n", strcmp(s, ss));
	printf("A - ft_strcmp: %d\n", ft_strcmp(s, ss));
	printf("Try ft_strcmp with 1 empty string as second argument\n");
	printf("S ---- strcmp: %d\n", strcmp(ss, s));
	printf("A - ft_strcmp: %d\n", ft_strcmp(ss, s));
	printf("Try ft_strcmp with multiple strings, equal or not, think about switching them\n");
	printf("S ---- strcmp: %d\n", strcmp(ss, ss1));
	printf("A - ft_strcmp: %d\n", ft_strcmp(ss, ss1));
	printf("S ---- strcmp: %d\n", strcmp(ss1, ss));
	printf("A - ft_strcmp: %d\n", ft_strcmp(ss1, ss));
	printf("S ---- strcmp: %d\n", strcmp(sl, sl));
	printf("A - ft_strcmp: %d\n", ft_strcmp(sl, sl));
	printf("\n-------------------------------------------------------FT_WRITE-------------------------------------------------------\n");
	printf("Try ft_write with the stdout\nTry ft_strcpy with a empty string\n");
	printf(" <- S - %zd\n", write(1, s, strlen(s)));
	printf(" <- A - %zd\n", ft_write(1, s, ft_strlen(s)));
	printf("Try ft_strcpy with a short string\n");
	printf(" <- S - %zd\n", write(1, ss, strlen(ss)));
	printf(" <- A - %zd\n", ft_write(1, ss, ft_strlen(ss)));
	printf("Try ft_strcpy with a very long string\n");
	printf(" <- S - %zd\n", write(1, sl, strlen(sl)));
	printf(" <- A - %zd\n", ft_write(1, sl, ft_strlen(sl)));
	printf("Try ft_write with an open file descriptor\n");
	fd = open("text.txt", O_RDWR|O_APPEND|O_CREAT,S_IWRITE|S_IREAD);
	printf("S - %zd\n", write(fd, sl, strlen(sl)));
	write(fd, "\n", 1);
	printf("A - %zd\n", ft_write(fd, sl, ft_strlen(sl)));
	ft_write(fd, "\n", 1);
	printf("Try ft_write with a wrong file descriptor\n");
	ft_write(666, ss, ft_strlen(ss));
	errno = 0;
	printf("S - %zd (Errno: %s)\n", write(666, ss, strlen(ss)), strerror(errno));
	errno = 0;
	printf("A - %zd (Errno: %s)\n", ft_write(666, ss, ft_strlen(ss)), strerror(errno));
	errno = 0;
	close(fd);
	printf("\n-------------------------------------------------------FT_READ-------------------------------------------------------\n");
	printf("Try ft_read with the stdin\n");
	returns = read(0, buff, 400);
	printf("S - %zd\n", returns);
	returns = ft_read(0, buff, 400);
	printf("A - %zd\n", returns);
	close(fd);
	printf("Try ft_read with an open file descriptor\n");
	fd = open("text.txt", O_RDONLY);
	printf("S - %zd\n", read(fd, buff, 400));
	close(fd);
	fd = open("text.txt", O_RDONLY);
	printf("A - %zd\n", ft_read(fd, buff, 400));
	close(fd);
	printf("Try ft_read with a wrong file descriptor\n");
	fd = open("a1.txt", O_RDONLY);
	printf("A - %zd (Errno: %s)\n", read(fd, buff, 400), strerror(errno));
	errno = 0;
	close(fd);
	fd = open("a1.txt", O_RDONLY);
	printf("A - %zd (Errno: %s)\n", read(fd, buff, 400), strerror(errno));
	errno = 0;
	close(fd);
	printf("\n-------------------------------------------------------FT_STRDUP-------------------------------------------------------\n");
	printf("Try ft_strdup with an empty string\n");
	printf("S - %s\n", strdup(s));
	printf("A - %s\n", ft_strdup(s));
	printf("Try ft_strdup with a short string\n");
	printf("S - %s\n", strdup(ss));
	printf("A - %s\n", ft_strdup(ss));
	printf("Try ft_strdup with a very long string\n");
	printf("S - %s\n", strdup(sl));
	printf("A - %s\n", ft_strdup(sl));	
	return (0);
}