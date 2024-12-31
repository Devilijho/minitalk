/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:40:48 by safuente          #+#    #+#             */
/*   Updated: 2024/12/31 16:43:10 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power == 0)
		return (1);
	nb = nb * (ft_recursive_power(nb, power - 1));
	return (nb);
}

char	bin_to_ascii(char *msg)
{
	int	i;
	int	c;
	int	mul;

	i = 0;
	c = 0;
	mul = ft_strlen(msg) - 1;
	while (msg[i])
	{
		c += ((msg[i] - 48) * ft_recursive_power(2, mul));
		mul--;
		i++;
	}
	return (c);
}

char	*msg_assembler(int c)
{
	static char	*msg;
	char		*temp;

	if (!msg)
		msg = ft_strdup("");
	temp = msg;
	if (c == SIGUSR1)
		msg = ft_strjoin(temp, "0");
	else if (c == SIGUSR2)
		msg = ft_strjoin(temp, "1");
	free(temp);
	if (ft_strlen(msg) == 8)
		return (msg);
	return (NULL);
}

void	signal_handler(int signal)
{
	char	*msg;
	char	c;

	msg = msg_assembler(signal);
	if (msg != NULL)
	{
		ft_printf("Message recieved ->%s\n", msg);
		c = bin_to_ascii(msg);
		ft_putchar(c);
		free(msg);
	}
}

int	main(void)
{
	int			pid;

	pid = getpid();

	ft_printf("%d\n", pid);
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
	}
	return (0);
}
