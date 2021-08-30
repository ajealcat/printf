/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:05:10 by ajearuth          #+#    #+#             */
/*   Updated: 2021/08/30 11:31:32 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

int     ft_printf(const char *str, ...);
int	    ft_parse_and_count(char flag, va_list arg);
int     ft_print_percentage(void);
int     ft_print_c(va_list arg);
int     ft_print_s(va_list arg);
int     ft_print_d_i(va_list arg);
int     ft_print_u(va_list arg);
int     ft_print_p(va_list arg);
int     ft_print_x(va_list arg);
int     ft_print_upp_x(va_list arg);
int     ft_nbrlen(int nb, int base);
int		ft_unbrlen(unsigned int nb, int base);
void	ft_putnbr_uint_base_fd(unsigned int nb, const char *base, int fd);

#endif
