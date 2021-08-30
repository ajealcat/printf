/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 13:34:31 by ajearuth          #+#    #+#             */
/*   Updated: 2021/08/30 13:46:58 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_nbrlen(int nb, int base)
{
    int  i;

    i = 0;
	if (nb < 0)
		++i;
	if (nb == 0)
		return(1);
    while(nb != 0)
    {
        nb = nb / base;
        ++i;
    }
    return(i);
}

int	ft_unbrlen(unsigned int nb, int base)
{
	unsigned int i;

	i = 0;
	if (nb == 0)
		return(1);
	while(nb != 0)
	{
		nb = nb / base;	
		++i;
	}
	return(i);
}

void	ft_putnbr_uint_base_fd(unsigned int nb, const char *base, int fd)
{
	if (nb < ft_strlen(base) && nb >= 0)
		ft_putchar_fd(base[nb], fd);
	else
	{
		ft_putnbr_uint_base_fd(nb / ft_strlen(base), base, fd);
		ft_putnbr_uint_base_fd(nb % ft_strlen(base), base, fd);
	}
}

int	ft_unbrlen_p(uint64_t nb, int base)
{
	unsigned int i;

	i = 0;
	if (nb == 0)
		return(1);
	while(nb != 0)
	{
		nb = nb / base;	
		++i;
	}
	return(i);
}

void	ft_putnbr_uint_base_p_fd(uint64_t nb, const char *base, int fd)
{
	if (nb < ft_strlen(base) && nb >= 0)
		ft_putchar_fd(base[nb], fd);
	else
	{
		ft_putnbr_uint_base_p_fd(nb / ft_strlen(base), base, fd);
		ft_putnbr_uint_base_p_fd(nb % ft_strlen(base), base, fd);
	}
}
