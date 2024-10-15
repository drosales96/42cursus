/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:52:47 by marigome          #+#    #+#             */
/*   Updated: 2024/10/15 10:47:26 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* COMO FUNCIONA EXIT:
 
 - Descriptores de archivo en el sistema:
  mEn Unix y Linux, el sistema utiliza tres descriptores de archivo predeterminados:

    STDIN_FILENO (0): Entrada estándar.
    STDOUT_FILENO (1): Salida estándar.
    STDERR_FILENO (2): Salida de error estándar. 

    Cuando ocurre un error, como en el caso de un argumento no válido en el comando exit, 
    el mensaje de error debe ser enviado a la salida de error estándar (STDERR_FILENO), 
    porque es el lugar adecuado para reportar errores, mientras que la salida estándar (STDOUT_FILENO) 
    se utiliza para los resultados normales del programa.

 - Exit:
  * 255 -> Arg no numérico y valor fuera de rango (long long min y long long max)
  * 0 -> Éxito

- */



static long long ft_atol(char *str)
{
    long long	result;
    int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int  ft_checker_num(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (-1);
        i++;
    }
    return (OK);
}

int ft_exit(t_ast *cmd)
{
    long long exit_value;

	exit_value = 0;
	if (cmd->left == NULL)
    {
        ft_putstr_fd("You left minihell succesfully! 🫰\n", STDOUT);
        exit(0);
    }
    if (ft_checker_num(cmd->left->value) == -1)
    {
        ft_putendl_fd(ft_get_error_message(ERR_MSG_EXIT_NUMBER_REQUIRED), STDERR_FILENO);
        exit (255);
    }
    if (cmd->left->right != NULL)
    {
        ft_putendl_fd(ft_get_error_message(ERR_MSG_EXIT_TOO_MANY_ARGS), STDERR_FILENO);
        return (1);
    }
	exit_value = ft_atol(cmd->left->value);
	if (exit_value > LLONG_MAX || exit_value < LLONG_MIN)
	{
		ft_putendl_fd(ft_get_error_message(ERR_MSG_EXIT_NUMBER_REQUIRED), STDERR_FILENO);
		exit (255);
	}
	ft_putendl_fd("exit", STDOUT_FILENO);
	exit(exit_value % 256);
}