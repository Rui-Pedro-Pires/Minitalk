/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:32:45 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/14 12:53:39 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# define _XOPEN_SOURCE 500
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "./include/ft_printf/ft_printf.h"
# include "./include/libft/libft.h"

int		ft_send_bits(char **argv);
void	handler(int signal);

#endif