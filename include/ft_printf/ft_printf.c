/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:19:53 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/06 15:56:01 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd_printf(va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd_printf(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_put_pointer(va_arg(args, unsigned long long), 1));
	else if (c == 'd')
		return (ft_putnbr_fd_printf(va_arg(args, int), 1));
	else if (c == 'i')
		return (ft_putnbr_fd_printf(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1));
	else if (c == 'x')
		return (ft_putnbr_base_lower_fd(va_arg(args, unsigned int), 1));
	else if (c == 'X')
		return (ft_putnbr_base_upper_fd(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (ft_putchar_fd_printf(c, 1));
	else
		return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	int			i;

	va_start(args, input);
	i = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			i += ft_check(*input, args);
		}
		else
			i += ft_putchar_fd_printf(*input, 1);
		input++;
	}
	va_end(args);
	return (i);
}
