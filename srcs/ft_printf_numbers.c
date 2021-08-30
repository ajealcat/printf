/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:12:44 by ajearuth          #+#    #+#             */
/*   Updated: 2021/08/30 13:46:59 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d_i(va_list arg)
{
	int	nb;

	nb = va_arg(arg, int);
	ft_putnbr_fd(nb, 1);
	return(ft_nbrlen(nb, 10));
}

int	ft_print_u(va_list arg)
{
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	ft_putnbr_uint_base_fd(nb, "0123456789", 1);
	return (ft_unbrlen(nb, 10));
}

int	ft_print_x(va_list arg)
{
	int	nb;

	nb = va_arg(arg, unsigned int);
    ft_putnbr_uint_base_fd(nb, "0123456789abcdef", 1);
	return(ft_unbrlen(nb, 16));
}

int	ft_print_upp_x(va_list arg)
{
	int	nb;

	nb = va_arg(arg, unsigned int);
    ft_putnbr_uint_base_fd(nb, "0123456789ABCDEF", 1);
	return(ft_unbrlen(nb, 16));
}
int	ft_print_p(va_list arg)
{
	uint64_t	adress;

	adress = va_arg(arg, uint64_t);
	ft_putstr_fd("0x", 1);
	ft_putnbr_uint_base_p_fd(adress, "0123456789abcdef", 1);
    return(ft_unbrlen_p(adress, 16) + 2);
}