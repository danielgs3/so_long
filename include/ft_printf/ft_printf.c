/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:33:13 by danielg3          #+#    #+#             */
/*   Updated: 2025/07/08 09:58:52 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	converter(char const *format, int *count, va_list args)
{
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (*format == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (*format == '%')
		ft_putchar('%', count);
	else if (*format == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), count);
	else if (*format == 'p')
		ft_putptr(va_arg(args, void *), count);
	else if (*format == 'x')
		ft_puthex(va_arg(args, unsigned int), count);
	else if (*format == 'X')
		ft_puthex_upper(va_arg(args, unsigned int), count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start (args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			converter(format, &count, args);
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
