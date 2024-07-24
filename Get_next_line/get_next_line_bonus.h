/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:31:05 by drosales          #+#    #+#             */
/*   Updated: 2024/05/28 10:09:59 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

//LIBS

# include <unistd.h>
# include <stdlib.h>

//MAIN FUNCTION

char	*get_next_line(int fd);

//UTILS FUNCTIONS

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

//BUFFER_SIZE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
