/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:57:46 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 11:56:45 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;

	if (size && nmemb > (__SIZE_MAX__ / size))
		return (NULL);
	ptr = (void *)malloc (nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, nmemb * size);
	return (ptr);
}
