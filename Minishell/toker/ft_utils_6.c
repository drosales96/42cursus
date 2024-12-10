/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:54:23 by marigome          #+#    #+#             */
/*   Updated: 2024/12/03 19:59:20 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_init_external_commands_part1(void)
{
	g_external_commands[0] = "cd";
	g_external_commands[1] = "export";
	g_external_commands[2] = "unset";
	g_external_commands[3] = "env";
	g_external_commands[4] = "exit";
	g_external_commands[5] = "clear";
	g_external_commands[6] = "pwd";
	g_external_commands[7] = "echo";
	g_external_commands[8] = "history";
	g_external_commands[9] = "alias";
	g_external_commands[10] = "unalias";
	g_external_commands[11] = "set";
	g_external_commands[12] = "unset";
	g_external_commands[13] = "type";
	g_external_commands[14] = "source";
	g_external_commands[15] = "fg";
	g_external_commands[16] = "bg";
	g_external_commands[17] = "jobs";
	g_external_commands[18] = "wait";
	g_external_commands[19] = "umask";
	g_external_commands[20] = "ls";
	g_external_commands[21] = "cat";
	g_external_commands[22] = "touch";
	g_external_commands[23] = "mkdir";
	g_external_commands[24] = "rmdir";
}

void	ft_init_external_commands_part2(void)
{
	g_external_commands[25] = "rm";
	g_external_commands[26] = "cp";
	g_external_commands[27] = "mv";
	g_external_commands[28] = "find";
	g_external_commands[29] = "locate";
	g_external_commands[30] = "tree";
	g_external_commands[31] = "basename";
	g_external_commands[32] = "dirname";
	g_external_commands[33] = "stat";
	g_external_commands[34] = "file";
	g_external_commands[35] = "chmod";
	g_external_commands[36] = "chown";
	g_external_commands[37] = "chgrp";
	g_external_commands[38] = "ln";
	g_external_commands[39] = "pwd";
	g_external_commands[40] = "clear";
	g_external_commands[41] = "uptime";
	g_external_commands[42] = "who";
	g_external_commands[43] = "whoami";
	g_external_commands[44] = "id";
	g_external_commands[45] = "hostname";
	g_external_commands[46] = "dmesg";
	g_external_commands[47] = "top";
}

void	ft_init_external_commands_part3(void)
{
	g_external_commands[48] = "htop";
	g_external_commands[49] = "ps";
	g_external_commands[50] = "kill";
	g_external_commands[51] = "killall";
	g_external_commands[52] = "jobs";
	g_external_commands[53] = "fg";
	g_external_commands[54] = "bg";
	g_external_commands[55] = "nohup";
	g_external_commands[56] = "reboot";
	g_external_commands[57] = "shutdown";
	g_external_commands[58] = "sync";
	g_external_commands[59] = "mount";
	g_external_commands[60] = "umount";
	g_external_commands[61] = "df";
	g_external_commands[62] = "du";
	g_external_commands[63] = "free";
	g_external_commands[64] = "vmstat";
	g_external_commands[65] = "lsof";
	g_external_commands[66] = "strace";
	g_external_commands[67] = "iostat";
	g_external_commands[68] = "ping";
	g_external_commands[69] = "wget";
	g_external_commands[70] = "curl";
}

void	ft_init_external_commands_part4(void)
{
	g_external_commands[71] = "ssh";
	g_external_commands[72] = "scp";
	g_external_commands[73] = "ftp";
	g_external_commands[74] = "nc";
	g_external_commands[75] = "telnet";
	g_external_commands[76] = "ifconfig";
	g_external_commands[77] = "ip";
	g_external_commands[78] = "route";
	g_external_commands[79] = "netstat";
	g_external_commands[80] = "ss";
	g_external_commands[81] = "nslookup";
	g_external_commands[82] = "dig";
	g_external_commands[83] = "traceroute";
	g_external_commands[84] = "curl";
	g_external_commands[85] = "wget";
	g_external_commands[86] = "tar";
	g_external_commands[87] = "gzip";
	g_external_commands[88] = "gunzip";
	g_external_commands[89] = "zip";
	g_external_commands[90] = "unzip";
	g_external_commands[91] = "bzip2";
	g_external_commands[92] = "xz";
}

void	ft_init_external_commands_part5(void)
{
	g_external_commands[93] = "7z";
	g_external_commands[94] = "grep";
	g_external_commands[95] = "sed";
	g_external_commands[96] = "awk";
	g_external_commands[97] = "cut";
	g_external_commands[98] = "sort";
	g_external_commands[99] = "uniq";
	g_external_commands[100] = "tee";
	g_external_commands[101] = "wc";
	g_external_commands[102] = "diff";
	g_external_commands[103] = "patch";
	g_external_commands[104] = "tr";
	g_external_commands[105] = "cmp";
	g_external_commands[106] = "comm";
	g_external_commands[107] = "join";
	g_external_commands[108] = "ps";
	g_external_commands[109] = "top";
	g_external_commands[110] = "bg";
	g_external_commands[111] = "fg";
	g_external_commands[112] = "jobs";
	g_external_commands[113] = "kill";
	g_external_commands[114] = "nohup";
}
