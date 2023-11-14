/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:32:24 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/14 17:09:47 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

void	handler(int signal)
{
	static char	c = 0;
	static int	i = 0;

	if (i <= 7)
	{
		if (signal == SIGUSR1)
			c |= 1;
		if (i != 7)
			c = (c << 1);
		i++;
	}
	if (i == 8)
	{
		write (1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_handler = handler;
	action.sa_flags = 0;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		exit(0);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		exit(1);
	ft_printf("Processor ID: ");
	ft_printf("%d\n", getpid());
	while (1)
	{
		pause();
	}
}
