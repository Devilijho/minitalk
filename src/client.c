/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:40:43 by safuente          #+#    #+#             */
/*   Updated: 2024/12/31 17:28:23 by safuente         ###   ########.fr       */
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
	if (ac < 3)
		return (1);
	signal.pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		ft_printf("Message n*%d sended\n", i);
		signal.bin = int_to_bin(av[2][i]);
		signal.msg = ft_itoa(signal.bin);
		send_message(&signal);
		ft_printf("Message sended ->%s\n", signal.msg);
		free(signal.msg);
		i++;
		// sleep(1);//
	}
	return (0);
}
