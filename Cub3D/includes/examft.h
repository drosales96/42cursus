/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-21 06:43:17 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-08-21 06:43:17 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef EXAMFT_H
# define EXAMFT_H

# include <stdlib.h>
# include <unistd.h> 
# include "libft.h"

/**
* 	Functions with main level1:
*		• ft_first_word.c
*		• ft_fizzbuzz.c
*		• ft_repeat_alpha.c
*		• ft_rev_print.c
*		• ft_rot_13.c
*		• ft_rotone.c
*		• ft_search_and_replace.c
*		• ft_ulstr.c
*
*	Functions with main level2:
*		• ft_alpha_mirror.c
*		• ft_camel_to_snake.c
*		• ft_do_op.c
*		• ft_inter.c
*		• ft_last_word.c
*		• ft_snake_to_camel.c
*		• ft_union.c
*		• ft_wdmatch.c
*
*	Functions with main level3:
*		• ft_add_prime_sum.c
*		• ft_epur_str.c
*		• ft_expand_str.c
*		• ft_hidenp.c
*		• ft_paramsum.c
*		• ft_pgcd.c
*		• ft_print_hex.c
*		• ft_rstr_capitalizer.c
*		• ft_str_capitalizer.c
*		• ft_tab_mult.c
*
*	Functions with main level4:
*		• ft_fprime.c
*		• ft_rev_wstr.c
*		• ft_rostring.c
*
*/

/** Structure to represent a node of my list. Their members are:
*     • data: the information contained by the node.
*     • void *: allows you to save any type of information.
*	  • int: type integer.
*     • next: the address of the next node, or NULL if the 
*             next node is the last.
*	Designed for ft_list_size.c / ft_list_foreach.c / ft_list_remove_if.c 
*				 sort_list.c
*
*/
typedef struct s_list_2
{
	int				data;
	struct s_list_2	*next;
}	t_list_2;

typedef struct s_list_3
{
	void			*data;
	struct s_list_3	*next;
}	t_list_3;

/** Structure to flood_fill 
*
*
*/
typedef struct s_point_1
{
	int	x;
	int	y;
}		t_point_1;

// ============================================================================
// Functions of level1
// ============================================================================
void			ft_putstr_2(char *str);
char			*ft_strcpy(char *s1, char *s2);
size_t			ft_strlen(const char *s);
void			ft_swap_2(int *a, int *b);

// ============================================================================
// Functions of level2
// ============================================================================
int				ft_atoi(const char *str);
int				ft_is_power_of_2(unsigned int n);
int				ft_max(int *tab, unsigned int len);
void			ft_print_bits(unsigned char octet);
unsigned char	ft_reverse_bits(unsigned char octet);
int				ft_strcmp(char *s1, char *s2);
size_t			ft_strcspn(const char *s, const char *reject);
char			*ft_strdup(const char *src);
char			*ft_strpbrk(const char *s1, const char *s2);
char			*ft_strrev(char *str);
size_t			ft_strspn(const char *s, const char *accept);
unsigned char	ft_swap_bits(unsigned char octet);

// ============================================================================
// Functions of level3
// ============================================================================
int				ft_atoi_base(const char *str, int str_base);
unsigned int	ft_lcm(unsigned int a, unsigned int b);
int				ft_list_size(t_list *begin_list);
int				*ft_range(int start, int end);
int				*ft_rrange(int start, int end);

// ============================================================================
// Functions of level4
// ============================================================================
void			ft_flood_fill(char **tab, t_point_1 size, t_point_1 begin);
char			*ft_itoa(int nbr);
void			ft_list_foreach(t_list_3 *begin_list, void (*f)(void *));
void			ft_list_remove_if(t_list_3 **begin_list, void *data_ref, \
int (*cmp)(void *, void*));
void			ft_sort_int_tab(int *tab, unsigned int size);
t_list_2		*ft_sort_list(t_list_2 *lst, int (*cmp)(int, int));
char			**ft_split(char const *s, char c);
char			**ft_split2(char *str);

#endif
