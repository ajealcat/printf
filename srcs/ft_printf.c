/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:42:58 by ajearuth          #+#    #+#             */
/*   Updated: 2021/08/27 12:39:06 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	int		count;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	ret = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_parse_and_count(str[i + 1], arg);
			++i;
		}
		else
		{
			write(1, &str[i], 1);
			++count;
		}
		++i;
	}
	va_end(arg);
	return (ret + count);
}

int		ft_parse_and_count(char flag, va_list arg)
{
	int	count;

	count = 0;
	if (flag == '%')
		count = ft_print_percentage(void);
	else if (flag == 'c')
		count = ft_print_c(arg);
	else if (flag == 's')
		count = ft_print_s(arg);
	else if (flag == 'd')
		count = ft_print_d(arg);
	else if (flag == 'i')
		count = ft_print_i(arg);
	else if (flag == 'u')
		count = ft_print_u(arg);
	else if (flag == 'p')
		count = ft_print_p(arg);
	else if (flag == 'x')
		count = ft_print_x(arg);
	else if (flag == 'X')
		count = ft_print_upp_x(arg);
	return (count);
}