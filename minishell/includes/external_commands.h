/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_commands.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:39:38 by marigome          #+#    #+#             */
/*   Updated: 2024/12/03 19:55:45 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTERNAL_COMMANDS_H
# define EXTERNAL_COMMANDS_H

# define EXTERNAL_COMMANDS_SIZE 160

extern const char	*g_external_commands[EXTERNAL_COMMANDS_SIZE];

void	ft_init_external_commands_part1(void);
void	ft_init_external_commands_part2(void);
void	ft_init_external_commands_part3(void);
void	ft_init_external_commands_part4(void);
void	ft_init_external_commands_part5(void);

#endif