/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:43:08 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 11:56:16 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	l_dst;
	size_t	l_src;
	size_t	dst_l;

	i = 0;
	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	dst_l = l_dst;
	if (siz == 0 || l_dst >= siz)
		return (siz + l_src);
	while (i < siz - dst_l - 1 && src[i])
		dst[l_dst++] = src[i++];
	dst[l_dst] = '\0';
	return (dst_l + l_src);
}
