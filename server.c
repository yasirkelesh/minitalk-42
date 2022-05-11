/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:07:11 by mukeles           #+#    #+#             */
/*   Updated: 2022/05/11 13:07:15 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	ft_action(int signum)
{
	static char		c = 0;
	static int		i = 0;

	c |= (signum == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (!c)
			ft_putchar_fd('\n', 1);
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_putstr_fd("server pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_action);
	signal(SIGUSR2, ft_action);
	while (2)
	{
		pause();
	}
}
