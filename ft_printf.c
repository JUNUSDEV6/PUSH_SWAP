/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:55:10 by yohanafi          #+#    #+#             */
/*   Updated: 2023/08/17 12:11:00 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg_lst;
	size_t	rlt;

	va_start(arg_lst, format);
	rlt = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == 32 && *(format + 2) == '%')
				rlt += ft_check_form('%', arg_lst);
			else
				rlt += ft_check_form(*(format + 1), arg_lst);
			format++;
		}
		else
			rlt += ft_putchar(*format);
		format++;
	}
	va_end(arg_lst);
	return (rlt);
}
