/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:06:31 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:06:31 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && (s[i] != c))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	count_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
	{
		i++;
	}
	return (i);
}

static void	free_str(size_t i, char **str)
{
	while (i > 0)
	{
		i--;
		free (*(str + i));
	}
	free(str);
}

static char	**create_word(char const *s, char c, char **str, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(str + i) = ft_substr(s, j, count_word_len(&*(s + j), c));
		if (!*(str + i))
		{
			free_str(i, str);
			return (0);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(str + i) = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	totalwords;

	if (!s)
		return (NULL);
	totalwords = count_words(s, c);
	str = (char **) malloc((totalwords + 1) * (sizeof(char *)));
	if (!str)
		return (NULL);
	str = create_word(s, c, str, totalwords);
	return (str);
}
