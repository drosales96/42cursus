/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:53:59 by drosales          #+#    #+#             */
/*   Updated: 2024/10/10 15:07:25 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_strnlen(const char *str, size_t maxlen)
{
    size_t len;

    len = 0;
    while (len < maxlen && str[len])
        len++;
    return (len);
}

char	*ft_strndup(const char *str, size_t n)
{
	char	*buffer;
	size_t	i;

	i = ft_strnlen(str, n);
	buffer = (char *)malloc((i + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	ft_memcpy(buffer, str, i);
    buffer[i] = '\0';
	return (buffer);
}

int ft_isspace(int c)
{
    if (c == 32 || (c >= 9 && c <= 13))
        return (1);
    return (0);
}
int ft_is_quote(int c)
{
    if (c == '\'' || c == '\"')
        return (1);
    return (0);
}

int ft_strcmp(const char *s1, const char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && (s1[i] == s2[i]))
        i++;
    return (s1[i] - s2[i]);
}