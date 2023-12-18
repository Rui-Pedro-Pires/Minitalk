/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:18:06 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/14 17:15:24 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk_bonus.h"

void	handler1(int signal)
{
	if (signal == SIGUSR1)
	{
		write(1, "Message Sent\n", 17);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	action.sa_handler = handler1;
	sigaction(SIGUSR1, &action, NULL);
	if (argc == 3)
	{
		ft_send_bits(argv);
		while (sigaction(SIGUSR1, &action, NULL) != 0)
		{
			if (sigaction(SIGUSR1, &action, NULL) == -1)
				exit(0);
			pause();
		}
	}
	else
		ft_printf("ERROR!\nSyntax: ./cliente_bonus <PID> <STRING TO SEND>\n");
	return (1);
}

void	ft_send_null(int pid)
{
	int		i;
	char	c;

	i = 7;
	c = '\0';
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

void	ft_send_bits(char **argv)
{
	int				i;
	int				j;
	unsigned char	c;

	i = 0;
	while (argv[2][i])
	{
		c = argv[2][i];
		j = 7;
		while (j >= 0)
		{
			if (((c >> j) & 1) == 1)
				kill(ft_atoi(argv[1]), SIGUSR1);
			else
				kill(ft_atoi(argv[1]), SIGUSR2);
			usleep(500);
			j--;
		}
		i++;
	}
	ft_send_null(ft_atoi(argv[1]));
}
