/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:54:08 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/06 15:55:08 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_pointer_recursive(unsigned long long n, int fd)
{
	if (n < 16)
	{
		write(fd, &"0123456789abcdef"[n], 1);
	}
	else
	{
		ft_put_pointer_recursive(n / 16, fd);
		ft_put_pointer_recursive(n % 16, fd);
	}
}

int	ft_put_pointer(unsigned long long n, int fd)
{
	int	x;

	if (n == 0)
		return (ft_putstr_fd_printf("(nil)", 1));
	else
	{
		x = ft_count_num_hex(n) + 2;
		write(fd, "0x", 2);
		ft_put_pointer_recursive(n, fd);
	}
	return (x);
}
