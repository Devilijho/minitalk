/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:40:48 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 20:09:08 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	signal_interpreter(int signal)
{
	static int	c;

	if (!c)
		c = 0;
	if (signal == SIGUSR1)
	{
		ft_printf("0");
		c = c * 10 + 0;
	}
	else if (signal == SIGUSR2)
	{
		ft_printf("1");
		c = c * 10 + 1;
	}
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("0");
	else if (signal == SIGUSR2)
		ft_printf("1");
}

int	main(void)
{
	int			pid;

	pid = getpid();

	ft_printf("%d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		continue ;
	return (0);
}
