/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <milletp.pro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:03:46 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/21 13:09:46 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strdup_split(char const *s, size_t s_len)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *)wrmalloc(sizeof(char) * (s_len + 1));
	if (str == NULL)
		return (NULL);
	while (i < s_len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	count_char(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	if (s[i] == '\0' && s[i - 1] != c)
		count++;
	return (count);
}

char	**ft_split2(const char *s, char **sentence, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			sentence[j] = strdup_split(s + i, count_char(s + i, c));
			if (sentence[j] == NULL)
				return (NULL);
			j++;
			while (s[i] && s[i] != c)
				i++;
			i--;
		}
		i++;
	}
	sentence[j] = NULL;
	return (sentence);
}

char	**ft_split(char const *s, char c)
{
	char	**sentence;

	if (s == NULL)
		return (NULL);
	sentence = (char **)wrmalloc(sizeof(char *) * ((count_words(s, c) + 1)));
	if (sentence == NULL)
		return (NULL);
	sentence = ft_split2(s, sentence, c);
	return (sentence);
}
