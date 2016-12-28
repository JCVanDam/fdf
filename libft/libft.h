/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:02:10 by maxpetit          #+#    #+#             */
/*   Updated: 2016/09/29 15:11:36 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFF_SIZE 42
# define RET gnl->ret
# define BUFF gnl->buff
# define SIZE gnl->size
# define POS gnl->pos
# define FD gnl->fd

typedef struct		s_gnl
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	int				pos;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**get_next_line
*/
int					get_next_line(int const fd, char **line);
size_t				ft_checkback(char *str, int *i);
int					ft_belong_list(t_list **lst, int fd, char *buff,
					int ret);
void				ft_new_el(int const fd, char *buff, t_list **lst);
int					ft_rm_elem(t_list **lst);
/*
**memory
*/
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
					size_t n);
void				*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
/*
**string
*/
void				ft_putstr_fd(const char *s, int fd);
void				ft_putstr_str_fd(const char *s1, const char *s2,
					const char *s3, int fd);
int					ft_countchr(char *src, char c);
size_t				ft_strlen(const char *s);
int					ft_strlenc(char *str, char c);
size_t				ft_strlen_printable(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strncat(char *restrict s1, const char *restrict s2,
					size_t n);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
					size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(char const *s1, char const *s2, size_t size);
char				*ft_strjoin_free(char *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strnew(size_t size);
char				*ft_put_endpath(char *path, char *file_name);
/*
**check
*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_check_strisalnum(char *str);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
/*
**print
*/
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putstr_str(char *str1, char *str2,
					char *str3, char *str4);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_padding(char orientation, char *str,
					size_t size, char elem);
/*
**list
*/
void				ft_lst_clear(t_list **begin_lst);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lst_push_back(t_list **list, void *data, size_t size);
t_list				*ft_lst_reverse(t_list **begin_list);
/*
**conversion
*/
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
/*
**tab
*/
int					ft_strlen_tab(char **tb);
void				ft_print_tab(char **tb);
char				**ft_strdup_tab(char **tb);
void				ft_free_tab(char ***tb);
void				ft_free_tab3dim(char ****tb);
int					ft_tab_srch_idx(char **tb, char *needle);

#endif
