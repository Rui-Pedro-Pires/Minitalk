/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:33:52 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/09 13:50:28 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *string);
void	*ft_calloc(size_t nitems, size_t size);
void	*ft_memchr(const void *str, int c, size_t n);
char	*ft_strnstr(const char *big, const char *lit, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s1, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
size_t	ft_strlen(const char *str);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_lstsize(t_list *lst);
int		ft_isalpha(int c);
int		ft_isdigit(int x);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_atoi(const char *str);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
int		ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_toupper(int ch);
int		ft_tolower(int ch);

#endif