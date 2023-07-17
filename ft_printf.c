/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:56:54 by mtoktas           #+#    #+#             */
/*   Updated: 2023/07/17 21:17:32 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_check(char c, va_list arg)
{
    int p;

    p = 0;
    if (c == 'c')
        p += ft_putchar(va_arg(arg, int));
    else if (c == 's')
        p += ft_putstr(va_arg(arg, char *));
    else if (c == 'd' || c == 'i')
        p += ft_putnbr(va_arg(arg, int));
    else if (c == 'u')
        p += ft_u(va_arg(arg, unsigned int));
    else if (c == 'x' || c == 'X')
        p += ft_x(va_arg(arg, unsigned int), c);
    else if (c == 'p')
    {
        p += ft_putstr("0x");
        p += ft_p(va_arg(arg, unsigned int));
    }
    else if (c == '%')
        p += ft_putchar('%');
    else
        return (ft_putchar(c));
    return (p);
}