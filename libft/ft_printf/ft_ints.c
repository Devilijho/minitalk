/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:03:42 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 13:29:30 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_connect(int nb)
{
	return (ft_putnbr_f(nb) + ft_count(nb));
}

int	ft_count(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	return (count + 1);
}

int	ft_count_signed(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	return (count + 1);
}

int	ft_putnbr_f(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr_f("-2");
		ft_putnbr_f(147483648);
		return (0);
	}
	if (nb < 0)
	{
		ft_putchar_f('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr_f(nb / 10);
	ft_putchar_f(nb % 10 + '0');
	return (0);
}

int	ft_putnbr_signed(unsigned int nb)
{
	if (nb > 9)
		ft_putnbr_signed(nb / 10);
	ft_putchar_f(nb % 10 + '0');
	return (ft_count_signed(nb));
}
