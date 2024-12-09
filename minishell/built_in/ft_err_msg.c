/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:00:58 by marigome          #+#    #+#             */
/*   Updated: 2024/12/04 19:35:21 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_get_error_message(t_err_msg error)
{
	if (error == ERR_MSG_COMMAND_NOT_FOUND)
		return ("error: command not found");
	else if (error == ERR_MSG_NO_SUCH_FILE)
		return ("error: no such file or directory");
	else if (error == ERR_MSG_PERM_DENIED)
		return ("error: permission denied");
	else if (error == ERR_MSG_TOO_MANY_ARGS)
		return ("error: too many arguments");
	else if (error == ERR_MSG_NUMBER_REQUIRED)
		return ("error: numeric argument required");
	else if (error == ERR_MSG_SYNTAX_ERROR)
		return ("error: syntax error");
	else if (error == ERR_MSG_INVALID_OPTION)
		return ("error: invalid option");
	else if (error == ERR_MSG_NOT_A_DIRECTORY)
		return ("error: not a directory");
	else if (error == ERR_MSG_FILE_EXISTS)
		return ("error: file already exists");
	else if (error == ERR_MSG_ENV_VAR_NOT_FOUND)
		return ("error: environment variable not found");
	else if (error == ERR_MSG_EXIT_TOO_MANY_ARGS)
		return ("bash: exit: too many arguments");
	else if (error == ERR_MSG_EXIT_NUMBER_REQUIRED)
		return ("bash: exit: numeric argument required");
	return ("error: Unknown error");
}
