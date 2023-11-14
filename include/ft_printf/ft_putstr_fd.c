/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:55:42 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/06 15:54:55 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_printf(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr_fd_printf("(null)", 1));
	while (s[i])
		write(fd, &s[i++], 1);
	return (i);
}
