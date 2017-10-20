/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 08:55:00 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/18 22:47:55 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		++i;
	}
	return (0);
}

int		is_word(char c, char cbefore, char *charset)
{
	return (!is_separator(c, charset) && is_separator(cbefore, charset));
}

int		get_words_count(char *str, char *charset)
{
	int	words_count;
	int	i;

	i = 0;
	words_count = 0;
	while (str[i] != '\0')
	{
		if (is_word(str[i], str[i - 1], charset) ||
			(!is_separator(str[i], charset) && i == 0))
			words_count++;
		i++;
	}
	return (words_count);
}

int		*get_words_size(char *str, char *charset)
{
	int	index;
	int	i;
	int	words_count;
	int	*words_size;

	i = 0;
	words_count = get_words_count(str, charset);
	words_size = malloc(words_count * sizeof(int));
	while (i <= words_count)
	{
		words_size[i] = 0;
		i++;
	}
	i = 0;
	index = 0;
	while (str[i] != '\0')
	{
		if (!is_separator(str[i], charset))
			words_size[index]++;
		else if (i > 0 && !is_separator(str[i - 1], charset))
			index++;
		i++;
	}
	return (words_size);
}

char	**ft_split(char *str, char *charset)
{
	char	**words;
	int		i;
	int		j;
	int		index;
	int		*words_size;

	words = malloc((get_words_count(str, charset) + 1) * sizeof(char*));
	words_size = get_words_size(str, charset);
	index = 0;
	j = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (!is_separator(str[i], charset))
		{
			if (i == 0 || is_word(str[i], str[i - 1], charset))
				words[index] = malloc(words_size[index] * sizeof(char));
			words[index][j] = str[i];
			words[index][++j] = '\0';
		}
		else if (i > 0 && !is_separator(str[i - 1], charset) && ++index)
			j = 0;
	}
	words[get_words_count(str, charset)] = 0;
	return (words);
}
