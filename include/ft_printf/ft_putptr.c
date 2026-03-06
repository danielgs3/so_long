/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:05:10 by danielg3          #+#    #+#             */
/*   Updated: 2025/07/01 13:41:36 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr, int *count)
{
	if (ptr == NULL)
		ft_putstr("(nil)", count);
	else
	{
		ft_putstr("0x", count);
		ft_puthex((unsigned long long)ptr, count);
	}
}
