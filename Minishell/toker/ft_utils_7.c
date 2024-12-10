/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:58:44 by marigome          #+#    #+#             */
/*   Updated: 2024/12/03 20:09:18 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

const char	*g_external_commands[EXTERNAL_COMMANDS_SIZE];

void	ft_init_external_commands_part6(void)
{
	g_external_commands[115] = "screen";
	g_external_commands[116] = "tmux";
	g_external_commands[117] = "gcc";
	g_external_commands[118] = "g++";
	g_external_commands[119] = "make";
	g_external_commands[120] = "python";
	g_external_commands[121] = "python3";
	g_external_commands[122] = "ruby";
	g_external_commands[123] = "perl";
	g_external_commands[124] = "node";
	g_external_commands[125] = "npm";
	g_external_commands[126] = "yarn";
	g_external_commands[127] = "mvn";
	g_external_commands[128] = "gradle";
	g_external_commands[129] = "go";
	g_external_commands[130] = "rust";
	g_external_commands[131] = "php";
	g_external_commands[132] = "java";
	g_external_commands[133] = "javac";
	g_external_commands[134] = "javap";
	g_external_commands[135] = "ant";
	g_external_commands[136] = "composer";
}

void	ft_init_external_commands_part7(void)
{
	g_external_commands[137] = "git";
	g_external_commands[138] = "svn";
	g_external_commands[139] = "hg";
	g_external_commands[140] = "make";
	g_external_commands[141] = "git";
	g_external_commands[142] = "svn";
	g_external_commands[143] = "diff";
	g_external_commands[144] = "patch";
	g_external_commands[145] = "meld";
	g_external_commands[146] = "man";
	g_external_commands[147] = "info";
	g_external_commands[148] = "which";
	g_external_commands[149] = "whereis";
	g_external_commands[150] = "sudo";
	g_external_commands[151] = "su";
	g_external_commands[152] = "env";
	g_external_commands[153] = "export";
	g_external_commands[154] = "unset";
	g_external_commands[155] = "alias";
	g_external_commands[156] = "unalias";
}

void	ft_init_external_commands_part8(void)
{
	g_external_commands[157] = "reboot";
	g_external_commands[158] = "shutdown";
	g_external_commands[159] = "clear";
}

int	ft_is_commands(char *value)
{
	int	i;

	i = 0;
	while (i < EXTERNAL_COMMANDS_SIZE)
	{
		if (ft_strcmp(value, g_external_commands[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	init_external_commands(void)
{
	ft_init_external_commands_part1();
	ft_init_external_commands_part2();
	ft_init_external_commands_part3();
	ft_init_external_commands_part4();
	ft_init_external_commands_part5();
	ft_init_external_commands_part6();
	ft_init_external_commands_part7();
	ft_init_external_commands_part8();
}
