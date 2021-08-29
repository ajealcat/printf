/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 07:51:04 by ajearuth          #+#    #+#             */
/*   Updated: 2021/08/29 13:32:20 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_print_percentage(void)
{
    ft_putchar_fd('%', 1);
	return (1);
}

int	ft_print_c(va_list arg)
{
	char	c;

	c = (char)va_arg(arg, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_s(va_list arg)
{
	char	*str;
	int		count;

	count = 0;
	str = va_arg(arg, char *);
	if (str == NULL)
         return (0);
	else
	{
		ft_putstr_fd(str, 1);
		count = ft_strlen(str);
	}
	return (count);
}

int	ft_print_d_i(va_list arg)
{
	int	nb;

	nb = va_arg(arg, int);
	ft_putnbr_fd(nb, 1);
	return(ft_strlen(ft_itoa(nb)));
}

int	ft_print_u(va_list arg)
{
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	ft_putnbr_uint(nb, 1);
	return (ft_count_uint(nb));
}