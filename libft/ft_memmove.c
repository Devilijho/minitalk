/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:35:53 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 11:56:25 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*ptr1;
	char		*ptr2;

	ptr1 = src;
	ptr2 = dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
		while (n-- > 0)
			ptr2[n] = ptr1[n];
	else
	{
		while (i < n)
		{
			ptr2[i] = ptr1[i];
			i++;
		}
	}
	return (dest);
}
