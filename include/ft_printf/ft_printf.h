/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:08:35 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/06 15:56:08 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_putchar_fd_printf(char c, int fd);
int	ft_putnbr_fd_printf(int n, int fd);
int	ft_putstr_fd_printf(char *s, int fd);
int	ft_putnbr_base_lower_fd(unsigned int n, int fd);
int	ft_putnbr_base_upper_fd(unsigned int n, int fd);
int	ft_printf(const char *input, ...);
int	ft_putnbr_unsigned_fd(unsigned int n, int fd);
int	ft_put_pointer(unsigned long long n, int fd);
int	ft_count_num(long n);
int	ft_count_num_hex(unsigned long n);

#endif
