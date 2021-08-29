/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 13:34:31 by ajearuth          #+#    #+#             */
/*   Updated: 2021/08/29 15:51:10 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_p(va_list arg)
{
	void	*adress;

	adress = va_arg(arg, void *);
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd((unsigned long long int)adress, "0123456789abcdef", 1);
    return(ft_nbrlen((unsigned long long int)adress, 16) + 2);
}

int	ft_print_x(va_list arg)
{
	int	nb;

	nb = va_arg(arg, unsigned int);
    ft_putnbr_base_fd(nb, "0123456789abcdef", 1);
	return(ft_nbrlen(nb, 16));
}

int	ft_print_upp_x(va_list arg)
{
	int	nb;

	nb = va_arg(arg, unsigned int);
    ft_putnbr_base_fd(nb, "0123456789ABCDEF", 1);
	return(ft_nbrlen(nb, 16));
}

int ft_nbrlen(unsigned long long int nb, int base)
{
    unsigned int  i;

    i = 0;
    while(nb != 0)
    {
        nb = nb / base;
        ++i;
    }
    return(i);
}

void	ft_putnbr_uint_fd(unsigned long long int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_uint_fd(n / 10, fd);
		ft_putnbr_uint_fd(n % 10, fd);
	}
	else if (n <= 9)
		ft_putchar_fd(n + 48, fd);
}