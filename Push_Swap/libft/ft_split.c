/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 07:20:38 by drosales          #+#    #+#             */
/*   Updated: 2024/08/07 08:47:22 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char    *ft_strncpy(char *dst, char *src, int len)
{
    int i = 0;

    while (i < len && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return(dst);
}

static int ft_isspace(int c)
{
    if (c == 32 || c == 9 || c == 10)
        return (1);
    return (0);
}

char    **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int wordlen = 0;

    while (str[i])
    {
        while (str[i] && ft_isspace(str[i]))
            i++;
        if (str[i])
            wordlen++;
        while (str[i] && !ft_isspace(str[i]))
            i++;
    }
    char    **res = (char **)malloc(sizeof(char *) * wordlen + 1);
    i = 0;
    if (!res)
        return(NULL);
    while (str[i])
    {
        while (str[i] && ft_isspace(str[i]))
            i++;
        j = i;
        while (str[i] && !ft_isspace(str[i]))
            i++;
        if (i > j)
        {
            res[k] = (char *)malloc(sizeof(char) * (i - j) + 1);
            if (!res)
                return (NULL);
            ft_strncpy(res[k++], &str[j] , i - j);
        }
    }
    res[k] = NULL;
    return (res);
}*/

static unsigned int	countwords(const char *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{	
		while (*s && c == *s)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static char	*ft_cpy(size_t i, char const *s, char c, char **split)
{
	int		index;
	size_t	j;

	index = -1;
	j = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split[j]);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((countwords(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	ft_cpy(i, s, c, split);
	return (split);
}
