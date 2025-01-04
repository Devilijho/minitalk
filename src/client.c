/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:40:43 by safuente          #+#    #+#             */
/*   Updated: 2025/01/04 12:08:53 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	int_to_bin(int c)
{
	int	binary;
	int	place;

	binary = 0;
	place = 1;
	if (c == 0)
		return (0);
	while (c > 0)
	{
		binary += (c % 2) * place;
		c = c / 2;
		place *= 10;
	}
	return (binary);
}

void	send_message(t_msg *signal)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(signal->msg);
	if (!signal->msg)
		return ;
	while (l++ < 8)
	{
		kill(signal->pid, SIGUSR1);
		usleep(1);
	}
	while (signal->msg[i])
	{
		if (signal->msg[i] == '0')
			kill(signal->pid, SIGUSR1);
		else if (signal->msg[i] == '1')
			kill(signal->pid, SIGUSR2);
		usleep(1);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_msg	signal;
	int		i;

	i = 0;
	if (ac != 3)
	{
		ft_printf("Check your parameters!");
		return (1);
	}
	signal.pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		signal.bin = int_to_bin(av[2][i]);
		signal.msg = ft_itoa(signal.bin);
		send_message(&signal);
		free(signal.msg);
		i++;
	}
	return (0);
}
