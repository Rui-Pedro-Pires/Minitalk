/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:18:13 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/14 17:14:46 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk_bonus.h"

void	handler(int signal, siginfo_t *info, void *ucontext_t)
{
	static char	c = 0;
	static int	i = 0;
	pid_t		pid;

	(void)ucontext_t;
	pid = info->si_pid;
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
		if (c != '\0')
			write (1, &c, 1);
		else
			kill(pid, SIGUSR1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;
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
