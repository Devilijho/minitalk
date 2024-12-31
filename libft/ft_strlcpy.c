/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:27:45 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 11:56:16 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;

	i = 0;
	if (siz == 0)
		return (ft_strlen(src));
	while (i < siz - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (siz > 0)
		dst[i++] = '\0';
	return (ft_strlen(src));
}
