/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:30:12 by drosales          #+#    #+#             */
/*   Updated: 2024/06/07 18:16:16 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_putcharf(char c);
int		ft_putnbrf(int nb);
int		ft_putstrf(char *s);
int		ft_putunsgf(unsigned int n);
int		ft_puthex(unsigned long long nb, char c);
int		ft_pointer(uintptr_t ptr);

int		ft_printf(const char *str, ...);

#endif
