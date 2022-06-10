/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 02:50:44 by qdam              #+#    #+#             */
/*   Updated: 2021/04/22 02:50:44 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <wchar.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>

typedef unsigned char	t_uchar;

void		*ft_memset(void *dest, int c, size_t len);
void		ft_bzero(void *b, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t len);
void		*ft_memccpy(void *dst, const void *src, int c, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *b, int c, size_t len);
int			ft_memcmp(const void *b1, const void *b2, size_t len);

size_t		ft_strlen(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strnstr(const char *str, const char *to_find, size_t n);
int			ft_atoi(const char *str);

void		*ft_calloc(size_t number, size_t size);
char		*ft_strdup(const char *str);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_putchar_fd(char c, int fd);
void		ft_putwchar_fd(wchar_t c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putwstr_fd(wchar_t *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

size_t		ft_len_s(ssize_t num, size_t base);
size_t		ft_len_u(size_t num, size_t base);
int			ft_stridx(char c, const char *str);
bool		ft_strhas(char c, const char *str);
void		ft_putfd_s_base(int fd, ssize_t num, char *base);
void		ft_putfd_u_base(int fd, size_t num, char *base);

#endif
