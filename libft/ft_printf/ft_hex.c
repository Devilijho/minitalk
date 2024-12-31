/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:17:39 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 13:08:38 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_connect_hex(int nb, char x)
{
	char	*hex;

	if (x == 'x')
	{
		hex = "0123456789abcdef";
		return (ft_puthex(nb, hex) + ft_count_hex(nb));
	}
	else
	{
		hex = "0123456789ABCDEF";
		return (ft_puthex(nb, hex) + ft_count_hex(nb));
	}
}

int	ft_count_hex(unsigned int nb)
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

int	ft_puthex(unsigned int nb, char *hex)
{
	if (nb >= 16)
		ft_puthex(nb / 16, hex);
	ft_putchar_f(hex[nb % 16]);
	return (0);
}
