/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:39:26 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 18:58:52 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <signal.h>

typedef struct s_msg
{
	int		pid;
	int		bin;
	char	*msg;
}			t_msg;

#endif
