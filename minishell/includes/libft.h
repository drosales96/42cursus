/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:42:41 by marigome          #+#    #+#             */
/*   Updated: 2024/06/10 10:32:57 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

/// @brief if the character is a number between 0 & 9
/// @param c char
/// @return 0 || 1
int			ft_isdigit(int c);

/// @brief it check if c is a ASCII param (between 0 & 127, both includes)
/// @param c 
/// @return 0 || 1
int			ft_isascii(int c);

/// @brief check if c is <= a && <= z
/// @param c 
/// @return 0 || 1
int			ft_isalpha(int c);

/// @brief Check if c is alfanumeric. It include (A - Z) && (a - z) && (0 - 9)
/// @param c 
/// @return 0 || 1
int			ft_isalnum(int c);

/// @brief Check if c is printeable ASCII character (32 <= c <= 126)
/// @param c 
/// @return 0 || 1
int			ft_isprint(int c);

/// @brief Check the length of the string
/// @param s 
/// @return size
size_t		ft_strlen(const char *s);

/// @brief If c is between a && z it returns c upper (-32)
/// @param c 
/// @return upper c
int			ft_toupper(int c);

/// @brief If c is between A && z it return c lower (+32)
/// @param c 
/// @return lower c
int			ft_tolower(int c);

/// @brief Check if c is in the string and in that case it 
///returns the pointer from the first occurrence
/// @param s string
/// @param c character to find
/// @return the pointer from the first occurrence
char		*ft_strchr(const char *s, int c);

/// @brief If c is in the string it returns the last ocurrence
///that has found (Start from the last position)
/// @param s string
/// @param c character to find
/// @return 
char		*ft_strrchr(const char *s, int c);

/// @brief It compares character by character between s1 & s2 (At most n times)
/// @param s1 string 1
/// @param s2 string 2
/// @param n n times
/// @return 0 if both are equal || + if S1 > S2 || - if S1 < S2
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/// @brief If dstsize <= src, we sum src + dstsize because buffer its ok.
///Otherwise, we sum src + dst (We need to return the
/// size of the final concatenation). Finally we concatenate
///and we protect the fuction with final NULL
/// @param dst string concatenated 
/// @param src string we add to dst
/// @param dstsize size of concatenation we want to do (In the best case)
/// @return the size of the concatenation
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

/// @brief Copy src in dst until the size is 
///smaller than dstsize -1 to add a final NULL
/// @param dst final string
/// @param src source string
/// @param dstsize number of characters to be copied
/// @return ft_len(src)
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

/// @brief Find needle into str at most len iteractions
/// @param str str where you look for
/// @param needle str that you need to find
/// @return a pointer where needle is || str if needle "" 
///|| 0 if needle is not at str
char		*ft_strnstr(const char *str, const char *needle, size_t len);

/// @brief It convert a type str number in type int number
/// @param str str where number is
/// @return int number or 0 if str has a number or tab or reseat || Otherwise 0;
int			ft_atoi(const char *str);

/// @brief It include c len bytes into pointer b
/// @param b pointer init
/// @param c character we want to include
/// @param len bytes we want to modify
/// @return 
void		*ft_memset(void *b, int c, size_t len);

/// @brief That fuction includes 0 n times into ptr
/// @param ptr 
/// @param n number of elements
void		ft_bzero(void *ptr, size_t n);

void		*ft_memcpy(void *dst, const void *src, size_t n);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

void		*ft_memmove(void *dst, const void *src, size_t len);

void		*ft_memchr(const void *s, int c, size_t n);

void		*ft_calloc(size_t nmemb, size_t size);

char		*ft_strdup(const char *s);

char		*ft_substr(const char *s, unsigned int start, size_t len);

char		*ft_strjoin(char const *s1, char const *s2);

char		*ft_strtrim(char const *s1, char const *set);

char		*ft_itoa(int n);

char		**ft_split(char const *s, char c);
/// @brief strmapi apply a function to each caract of s
/// @param s string we will apply f
/// @param f the function we want to apply to each character of s
/// f parameters: index and the character in that index (s[i]).
/// @return a new buffer with each caracter converted from f
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/// @brief Change each character of s directly
/// @param s buffer that will be changed
/// @param f the fuction we want to apply
/// f parameters: index and &s[i]
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
/// @brief  Reply ft_putchar (write c) in the way of fd
/// @param c character we want to write
/// @param fd fd type
void		ft_putchar_fd(char c, int fd);
/// @brief write a string in fd type
/// @param s string
/// @param fd fd type
void		ft_putstr_fd(char *s, int fd);

void		ft_putendl_fd(char *s, int fd);

void		ft_putnbr_fd(int n, int fd);

/// LISTAS ///
typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;
/// Creamos un nuevo nodo con el contenido de *content
t_list		*ft_lstnew(void *content);

/// @brief Pone el nuevo nodo al principio de la lista
/// @param lst **Lista
/// @param *new = Nuevo nodo que añadimos
void		ft_lstadd_front(t_list **lst, t_list *new);
/// @brief Cuenta los *nodos que hay en una lista
/// @param lst Lista
/// @return Counter
int			ft_lstsize(t_list *lst);
/// @brief Función que retorna el último elemento de la lista
/// @param lst Nodo en el que iteramos
/// @return El último elemento de la lista
t_list		*ft_lstlast(t_list *lst);
/// @brief  Añade un nodo al final de la lista
/// @param lst **nodo
/// @param new *nodo que añadimos al final de la lista
void		ft_lstadd_back(t_list **lst, t_list *new);
/// @brief Elimina el nodo
/// @param lst lista
/// @param del f (del)
void		ft_lstdelone(t_list *lst, void (*del)(void *));
/// @brief Elimina el ultimo nodo de la lista de listas
/// @param lst 
/// @param del 
void		ft_lstclear(t_list **lst, void (*del)(void *));
/// @brief Elimina de la lista completa todos los nodos
/// @param lst 
/// @param f 
void		ft_lstiter(t_list *lst, void (*f)(void *));
/// @brief Se le aplica la funcion a cada nodo de la lista generando uno nuevo
/// Y aplica del para eliminar la lista en caso de que el nodo no exista
/// @param lst 
/// @param f 
/// @param del 
/// @return 
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif