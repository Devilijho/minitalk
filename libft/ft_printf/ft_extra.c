/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:23:35 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 13:09:10 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(unsigned long long ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr_f("(nil)"));
	count = ft_putstr_f("0x") + ft_putptr(ptr);
	return (ft_count_ptr(ptr) + count);
}

int	ft_count_ptr(unsigned long long nb)
{
	int	count;

	count = 0;
	while (nb >= 16)
	{
		nb /= 16;
		count++;
	}
	return (count + 1);
}

int	ft_putptr(unsigned long long nb)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
		ft_putptr(nb / 16);
	ft_putchar_f(hex[nb % 16]);
	return (0);
}
