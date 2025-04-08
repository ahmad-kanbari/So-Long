/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:46:47 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/18 13:48:35 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef long long int	t_llint;

//array
void	ft_arrfree(char	**arr);
int		ft_arrlen(char **a);
void	ft_sort_int_tab(int *tab, int size);
void	ft_swap(int *a, int *b);
long	ft_abs(long n);
int		ft_do_op(char *num1, char *sign, char *num2);
int		ft_max(int *tab, unsigned int len);

//checkers
int		ft_find_next_prime(int nb);
int		ft_is_prime(int nb);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isblank(int c);
int		ft_iscntrl(int c);
int		ft_isgraph(int c);
int		ft_ishexdigit(int c);
int		ft_ispunct(int c);
int		ft_isspace(int c);
int		ft_isstrnbr(char *str);
double	ft_sqrt(double x);

//strings manipulation
int		ft_atoi_base(char *str, char *base);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
char	**ft_split2(char const *s, char c);
char	*ft_strcapitalize(char *str);
char	*strnjoin(char **s1, char **s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *s1, const char *s2);
int		ft_strcmp_insensitive(const char *s1, const char *s2);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strjoin_delim(int size, char **strs, char *sep);
int		ft_strreps(char	*line, char c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	first_word(char *str);
void	ft_swap(int *a, int *b);
size_t	ft_strcspn(const char *s, const char *reject);
char	*ft_strpbrk(const char *s1, const char *s2);
size_t	ft_strspn(const char *s, const char *accept);
void	ft_last_word(char *str);
void	ft_str_capitalizer(char *str);
void	ft_search_replace(char *str, char to_be_replaced, char new);
int		ft_strlen_c(char *str, char c);

//print_fd
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_base(int nbr, char *base, int fd);

//linked lists
void	ft_lstadd_back_cmp(t_list **lst, t_list *new, \
		int (*cmp)(void *, void *));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_pos_after(t_list **lst, t_list *new, int position);
void	ft_lstadd_front_cmp(t_list **lst, t_list *new, \
		int (*cmp)(void *, void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_lstdelcont(void *content);
void	ft_lstdelelem(t_list **lst, t_list *elem, void (*del)(void *));
void	ft_lstdelpos(t_list **head, int position);
t_list	*ft_lstget(t_list *lst, int index);
void	ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void *ptr);
void	ft_lstprint(t_list *ptr);
t_list	*ft_lstreverse(t_list **lst);
void	ft_lstsort(t_list **lst, int (*cmp)(void *, void *));
int		ft_lstswap_cont(t_list *lst1, t_list *lst2);
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
char	*ft_strdup_n(const char *s, size_t n);

//memory
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_print_bits(unsigned char octet);
void	*ft_malloc(size_t size);

#endif
