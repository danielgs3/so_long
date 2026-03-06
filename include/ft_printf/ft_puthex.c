/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:52:08 by danielg3          #+#    #+#             */
/*   Updated: 2025/07/01 13:27:20 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long long num, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num > 15)
		ft_puthex(num / 16, count);
	ft_putchar(hex[num % 16], count);
}
