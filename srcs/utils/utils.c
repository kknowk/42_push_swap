/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:51:22 by khorike           #+#    #+#             */
/*   Updated: 2023/07/05 13:58:50 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*get_word(char const **s, char c)
{
	char const	*start;
	char		*word;
	int			len;

	start = *s;
	len = 0;
	while (**s && **s != c)
	{
		(*s)++;
		len++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

static void	check_malloc(char **ptr, int word_count)
{
	int	i;

	if (!ptr)
	{
		i = 0;
		while (i < word_count)
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
	}
}

static void	split_string(char const *s, char c, char **result)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[i] = get_word(&s, c);
			if (!result[i])
				check_malloc(result, i);
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
}

char	**ft_space_split(char const *s, char c, t_error *wc)
{
	char	**result;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	wc->count = word_count;
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	split_string(s, c, result);
	return (result);
}
