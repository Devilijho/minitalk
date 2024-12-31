/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:54:35 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 13:29:31 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type(va_list args, char c)
{
	if (c == '%')
		return (ft_putchar_f('%'));
	else if (c == 'c')
		return (ft_putchar_f(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_f(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_ptr((long int)va_arg(args, void *)));
	else if (c == 'd')
		return (ft_connect(va_arg(args, int)));
	else if (c == 'i')
		return (ft_connect(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_signed(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_connect_hex(va_arg(args, int), c));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += type(args, str[i + 1]);
			i++;
		}
		else if (str[i] != '\0')
			count += ft_putchar_f(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
