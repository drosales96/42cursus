/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:50:40 by marigome          #+#    #+#             */
/*   Updated: 2024/06/12 09:59:59 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h> 

int	ft_found_c(int c);

int	ft_found_s(char *s, int counter);

int	ft_found_d(int c);

int	ft_found_hex(unsigned long long nb, char c);

int	ft_found_u(unsigned int n);

int	ft_found_p(uintptr_t ptr);

int	ft_printf(const char *s, ...);

#endif