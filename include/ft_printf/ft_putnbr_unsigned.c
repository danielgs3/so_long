/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:56:40 by danielg3          #+#    #+#             */
/*   Updated: 2025/06/30 14:05:10 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10, count);
		ft_putchar(n % 10 + '0', count);
	}
	else
		ft_putchar(n + '0', count);
}
