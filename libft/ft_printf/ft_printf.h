/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:00:07 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 13:29:33 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		type(va_list args, char c);
int		ft_putchar_f(int c);
int		ft_putstr_f(char *c);
int		ft_putnbr_f(int nb);
int		ft_puthex(unsigned int nb, char *hex);
int		ft_putptr(unsigned long long nb);
int		ft_putnbr_signed(unsigned int nb);
int		ft_count_signed(unsigned int nb);
int		ft_connect(int nb);
int		ft_connect_hex(int nb, char x);
int		ft_count_hex(unsigned int nb);
int		ft_count_ptr(unsigned long long nb);
int		ft_count(int nb);
int		ft_ptr(unsigned long long ptr);

#endif
