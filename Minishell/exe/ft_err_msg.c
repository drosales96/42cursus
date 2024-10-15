/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:00:58 by marigome          #+#    #+#             */
/*   Updated: 2024/10/15 11:13:54 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *ft_get_error_message(t_err_msg error)
{
    if (error == ERR_MSG_COMMAND_NOT_FOUND)
        return "Error: Command not found";
    else if (error == ERR_MSG_NO_SUCH_FILE)
        return "Error: No such file or directory";
    else if (error == ERR_MSG_PERM_DENIED)
        return "Error: Permission denied";
    else if (error == ERR_MSG_TOO_MANY_ARGS)
        return "Error: Too many arguments";
    else if (error == ERR_MSG_NUMBER_REQUIRED)
        return "Error: Numeric argument required";
    else if (error == ERR_MSG_SYNTAX_ERROR)
        return "Error: Syntax error";
    else if (error == ERR_MSG_INVALID_OPTION)
        return "Error: Invalid option";
    else if (error == ERR_MSG_NOT_A_DIRECTORY)
        return "Error: Not a directory";
    else if (error == ERR_MSG_FILE_EXISTS)
        return "Error: File already exists";
    else if (error == ERR_MSG_ENV_VAR_NOT_FOUND)
        return "Error: Environment variable not found";
    else if (error == ERR_MSG_EXIT_TOO_MANY_ARGS)
        return "bash: exit: too many arguments";  // Mensaje para exit con demasiados argumentos
    else if (error == ERR_MSG_EXIT_NUMBER_REQUIRED)
        return "bash: exit: numeric argument required";  
    return "Error: Unknown error";
}


