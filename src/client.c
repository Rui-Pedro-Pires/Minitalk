/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:32:28 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/14 17:14:14 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (!ft_send_bits(argv))
			return (0);
	}
	else
		ft_printf("ERROR!\nSyntax: ./cliente <PID> <STRING TO SEND>\n");
	return (1);
}

int	ft_send_bits(char **argv)
{
	int				i;
	int				j;
	unsigned char	c;

	i = 0;
	while (argv[2][i])
	{
		c = argv[2][i];
		if (c <= 255)
		{
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
		}
		i++;
	}
	return (1);
}
