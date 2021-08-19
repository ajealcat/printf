/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:42:58 by ajearuth          #+#    #+#             */
/*   Updated: 2021/08/19 12:17:20 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_is_charset(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'c' || str[i] == 's'|| str[i] == 'p' || str[i] == 'd' ||
				str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

void ft_cut(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '%')
	{
		write(1, str[i], 1);
		i++;
	}
	if (str[i] == '%')
	{
		while (ft_is_charset(str) != 1)
			i++;
	}
	while (str[i])
	{
		write(1, str[i], 1);
		i++
	}
}

int	ft_printf(const char *str, ...)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ''%')
		{	
			ft_putchar_fd(str[i], 1);
			i++;
		}
		if (str[i] == '%')
		{
			*str = *str + i + 1;
			while (ft_is_charset(str) == 1)
				i++;
		}
	}
}

