/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:24:57 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 11:56:10 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char c, const char *set)
{
	size_t	x;

	x = 0;
	while (set[x])
	{
		if (c == set[x])
			return (0);
		x++;
	}
	return (1);
}

static int	ft_count_start(const char *s1, char const *set, size_t i)
{
	size_t	count;

	count = 0;
	while (s1[i] && ft_check(s1[i], set) == 0)
	{
		i++;
		count++;
	}
	return (count);
}

static int	ft_count_end(const char *s1, char const *set, size_t i)
{
	size_t	count;

	count = 0;
	while (s1[i] && ft_check(s1[i], set) == 0)
	{
		i--;
		count++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	y;
	size_t	count;

	i = 0;
	y = ft_count_start(s1, set, i);
	count = y + ft_count_end(s1, set, ft_strlen(s1) - 1);
	if (ft_strlen(s1) != y)
		str = (char *) malloc (sizeof(char) * (ft_strlen(s1) - count + 1));
	else
		str = (char *) malloc (sizeof(char) * 1);
	if (!str)
		return (NULL);
	while (s1[y] && i < ft_strlen(s1) - count)
	{
		str[i] = s1[y];
		y++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
