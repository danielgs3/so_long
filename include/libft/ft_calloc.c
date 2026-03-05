/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:21:43 by danielg3          #+#    #+#             */
/*   Updated: 2026/01/19 12:14:20 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total;
	size_t			i;
	unsigned char	*m;

	total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size)
		return (NULL);
	m = malloc(nmemb * size);
	if (!m)
		return (NULL);
	i = 0;
	while (i < total)
	{
		m[i] = 0;
		i++;
	}
	return (m);
}
