/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:10:49 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 11:56:21 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_malloc(char **strs, int i)
{
	while (i--)
	{
		if (strs[i])
		{
			free(strs[i]);
			strs[i] = (NULL);
		}
	}
	free(strs);
	return (NULL);
}

static int	ft_check(char s, char c)
{
	if (c == s)
		return (1);
	if (s == '\0')
		return (1);
	return (0);
}

static	int	ft_count_chars(const char *s, char c, int start)
{
	int	chars;

	chars = 0;
	while (s[start] && s[start] != c)
	{
		start++;
		chars++;
	}
	return (chars);
}

static	char	**ft_copy(char **strs, char c, int words, const char *s)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < words)
	{
		if (ft_check(s[y], c) == 1)
			y++;
		else
		{
			x = 0;
			strs[i] = (char *) malloc ((ft_count_chars(s, c, y) + 1)
					* sizeof(char));
			if (!strs[i])
				return (free_malloc(strs, i));
			while (s[y] && ft_check(s[y], c) == 0)
				strs[i][x++] = s[y++];
			strs[i][x] = '\0';
			i++;
		}
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;
	int		i;

	i = 0;
	words = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (ft_check(s[i], c) == 0 && ft_check(s[i + 1], c) == 1)
			words++;
		i++;
	}
	strs = (char **) malloc ((words + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	if (!ft_copy(strs, c, words, s))
		return (NULL);
	strs[words] = 0;
	return (strs);
}
