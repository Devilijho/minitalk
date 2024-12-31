/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:14:42 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 11:56:12 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*pos;

	pos = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			pos = (char *)&s[i];
		i++;
	}
	if ((char)c == s[i])
		pos = (char *)&s[i];
	return (pos);
}
