/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:07:34 by drosales          #+#    #+#             */
/*   Updated: 2024/12/03 20:05:23 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_handle_quotes(t_quote_info *info)
{
	char	current_char;

	current_char = info->line[info->index + info->i];
	if (info->quote_char == ' ' && (current_char == '\'' \
	|| current_char == '\"'))
	{
		info->quote_char = current_char;
		info->size++;
		info->i++;
		return (1);
	}
	else if (current_char == info->quote_char)
	{
		info->quote_char = ' ';
		info->size++;
		info->i++;
		return (1);
	}
	return (0);
}

int	token_size(char *line, int *index)
{
	t_quote_info	info;

	info.line = line;
	info.quote_char = ' ';
	info.size = 0;
	info.index = *index;
	info.i = 0;
	while (line[info.index + info.i])
	{
		if (ft_handle_quotes(&info))
			continue ;
		if (info.quote_char == ' ' && (line[info.index + info.i] == ' ' \
		|| line[info.index + info.i] == '|' \
		|| line[info.index + info.i] == '<' \
		|| line[info.index + info.i] == '>'))
		{
			info.size++;
			break ;
		}
		info.size++;
		info.i++;
	}
	return (info.size + 1);
}

void	ft_handle_variable_expansion(char *value, int *i, t_mini *minishell)
{
	char	*var_name;
	char	*var_value;
	int		j;
	int		start;

	if (value[*i] == '$' && value[*i + 1] == '?')
	{
		i = ft_status(minishell, i);
		return ;
	}
	start = ++(*i);
	j = 0;
	while (value[*i + j] && (ft_isalnum(value[*i + j]) || value[*i + j] == '_'))
		j++;
	if (j > 0)
	{
		var_name = ft_strndup(&value[start], j);
		var_value = ft_find_env_var(minishell->list_env,
				minishell->export_list, var_name);
		if (var_value)
			ft_putstr_fd(var_value, STDOUT);
		free(var_name);
		*i += j;
	}
}

void	ft_handle_double_quotes(char *value, int *i, t_mini *minishell)
{
	(*i)++;
	while (value[*i] && value[*i] != '"')
	{
		if (value[*i] == '$')
			ft_handle_variable_expansion(value, i, minishell);
		else
		{
			ft_putchar_fd(value[*i], STDOUT);
			(*i)++;
		}
	}
	if (value[*i] == '"')
		(*i)++;
}
