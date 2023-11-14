/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_lower_fd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:54:59 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/11 09:55:25 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_lower_fd(unsigned int n, int fd)
{
	int	x;

	x = ft_count_num_hex(n);
	if (n < 16)
	{
		write(fd, &"0123456789abcdef"[n], 1);
	}
	else
	{
		ft_putnbr_base_lower_fd(n / 16, fd);
		ft_putnbr_base_lower_fd(n % 16, fd);
	}
	return (x);
}

int	ft_putnbr_base_upper_fd(unsigned int n, int fd)
{
	int	x;

	x = ft_count_num_hex(n);
	if (n < 16)
	{
		write(fd, &"0123456789ABCDEF"[n], 1);
	}
	else
	{
		ft_putnbr_base_upper_fd(n / 16, fd);
		ft_putnbr_base_upper_fd(n % 16, fd);
	}
	return (x);
}
