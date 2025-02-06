/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-21 06:43:10 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-08-21 06:43:10 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h> // para macros va_list, va_start, va_end y va_arg
# include <stdlib.h> //para typedef, malloc
# include <unistd.h> // para write
# include <stdint.h> // para tipo uintptr_t

// ============================================================================
// Main functions
// ============================================================================
int		ft_printf(char const *format, ...);

// ============================================================================
// Auxiliary functions
// ============================================================================
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_puthex(unsigned long long nb, char checker);
int		ft_putptr(uintptr_t ptr);
int		ft_putnbr_uns(unsigned int nb);

// ============================================================================
// Bonus Functions
// ============================================================================

#endif