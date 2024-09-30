/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:22:38 by drosales          #+#    #+#             */
/*   Updated: 2024/09/30 12:18:03 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static ft_strnlen(const char *str, size_t maxlen)
{
    size_t len;

    len = 0;
    while (len < maxlen && str[len])
        len++;
    return (len);
}

static char	*ft_strndup(const char *str, size_t n)
{
	char	*buffer;
	size_t	count;

	count = ft_strnlen(str, n);
	buffer = (char *)malloc((count + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	else
		ft_memcpy(buffer, str, count);
    buffer[i] = '\0';
	return (buffer);
}

static int ft_isspace(int c)
{
    if (c == 32 || c >= 9 && c <= 13)
        return (1);
    return (0);
}

static char *ft_take_element_between_quotes(char *input, int *i)
{
    char    *quote;
    char    *start;
    char    *token;

    quote = input[*i];
    (*i)++;
    start = input[*i];
    while (input[*i] && input[*i] != quote)
        (*i)++;
    token = ft_strndup(start, *i - (start - input));
    if (input[*i] == quote)
        (*i)++;
    return (token);
}

t_list  *ft_lexer(char  *input)
{
    int i;
    Token   *tokens;

    i = 0;
    tokens = NULL;
    while (input[i])
    {
        if (ft_isspace(input[i]))
            i++;
        if (input[i] == '\'' || input[i] == '\"')
            tokens = ft_adding_tokens(tokens, ft_take_element_between_quotes(input, &i));
    }
}