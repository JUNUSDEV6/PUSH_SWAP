/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_form.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:11:11 by yohanafi          #+#    #+#             */
/*   Updated: 2023/08/08 12:31:19 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_check_form(char c, va_list arg_lst)
{
	size_t	rlt;

	rlt = 0;
	if (c == 'c')
		rlt += ft_putchar(va_arg(arg_lst, int));
	if (c == 's')
		rlt += ft_putstr(va_arg(arg_lst, char *));
	if (c == 'd' || c == 'i')
		rlt += ft_putnbr(va_arg(arg_lst, int));
	if (c == '%')
		rlt += ft_putchar('%');
	if (c == 'p')
		rlt += ft_putstr("0x")
			+ft_putnbr_base(va_arg(arg_lst, unsigned long), "0123456789abcdef");
	if (c == 'u')
		rlt += ft_putnbr_base(va_arg(arg_lst, unsigned), "0123456789");
	if (c == 'x')
		rlt += ft_putnbr_base(va_arg(arg_lst, unsigned), "0123456789abcdef");
	if (c == 'X')
		rlt += ft_putnbr_base(va_arg(arg_lst, unsigned), "0123456789ABCDEF");
	return (rlt);
}

size_t	ft_putnbr(long int nbr)
{
	size_t	length;

	length = 0;
	if (nbr < 0)
	{
		length += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		length += ft_putnbr(nbr / 10);
		length += ft_putnbr(nbr % 10);
	}
	else
		length += ft_putchar(nbr + 48);
	return (length);
}

size_t	ft_putnbr_base(unsigned long int nbr, const char *base)
{
	size_t		len;
	size_t		base_len;

	base_len = ft_strlen(base);
	len = 0;
	if (nbr < base_len)
		len += ft_putchar(base[nbr]);
	else
	{
		len += ft_putnbr_base(nbr / base_len, base);
		len += ft_putnbr_base(nbr % base_len, base);
	}
	return (len);
}
