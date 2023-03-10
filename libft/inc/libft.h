/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:14:37 by mhug              #+#    #+#             */
/*   Updated: 2023/03/10 09:17:47 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>

# define PI 3.141592654

typedef struct s_list	t_list;
typedef struct s_dlist	t_dlist;

/*
** <string.h>
*/
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
void		ft_strdel(char **as);
void		ft_strarrdel(char ***arr);

void		ft_memdel(void **ap);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memalloc(size_t size);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

char		*ft_strdup(const char *s);

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);

char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		ft_bzero(void *s, size_t n);

/*
** <stdlib.h>
*/
void		*ft_calloc(size_t count, size_t size); /* /!\ */

/*
** <ctype.h>
*/
int			ft_islower(int c);
int			ft_isupper(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isxdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_isblank(int c);
int			ft_str_isdigit(char *str);

int			ft_toupper(int c);
int			ft_tolower(int c);

/*
** <stdlib.h>
*/
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
long long	ft_atoll(const char *str);
int			ft_atoi_base(const char *str, int base_len);

/*
** <math.h>
*/
int			ft_abs(int n);
int			ft_min(int a, int b);
int			ft_max(int a, int b);
int			ft_clamp(int n, int min, int max);
double		deg_to_rad(double angle);

/*
** Custom functions
*/
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		**ft_split_set(char const *s, char *set);
void		ft_free(void **ptr);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strcatdup(char *buf1, char *buf2, int free1, int free2);
char		*ft_strndup(char *src, int len);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/*
** array functions
*/
size_t		ft_arr_str_len(char **arr);

struct s_list
{
	void	*content;
	t_list	*next;
};

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstfind(t_list *begin_list, void *data_ref, int (*cmp)());
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

struct s_dlist
{
	void	*content;
	t_dlist	*next;
	t_dlist	*prev;
};

t_dlist		*ft_dlstnew(void *content);
t_dlist		*ft_dlstlast(t_dlist *head);
void		ft_dlstadd_front(t_dlist **head, t_dlist *new);
void		ft_dlstadd_back(t_dlist **head, t_dlist *new);
int			ft_dlstsize(t_dlist *lst);
t_dlist		*ft_dlstfind(t_dlist *head, void *content,
				int (*cmp)(void *, void *));
void		ft_dlstinsert_after(t_dlist *elem, t_dlist *new);
void		ft_dlstinsert_before(t_dlist **head, t_dlist *token, t_dlist *new);
void		ft_dlstiter(t_dlist *head, void (*f)(void *));
void		ft_dlstdelone(t_dlist **head, t_dlist *elem, void (*del)(void *));
void		ft_dlstclear(t_dlist **lst, void (*del)(void *));
void		ft_dlstdelif(t_dlist **head, void *data_ref,
				int (*cmp)(), void (*del)(void *));

#endif
