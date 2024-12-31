/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:34:28 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 11:56:11 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;
	size_t	x;

	i = 0;
	x = 0;
	y = 0;
	(void)len;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[y] && y < len)
	{
		i = 0;
		x = y;
		while (little[i] == big[x] && x < len)
		{
			if (i == ft_strlen(little) - 1)
				return ((char *)big + y);
			x++;
			i++;
		}
		y++;
	}
	return (NULL);
}
