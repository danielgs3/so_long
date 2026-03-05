/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:21:19 by danielg3          #+#    #+#             */
/*   Updated: 2025/05/29 18:49:34 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*res;
	char			cc;

	cc = (char)c;
	res = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
		{
			res = (char *)&s[i];
		}
		i++;
	}
	if (s[i] == cc)
		res = (char *)&s[i];
	return (res);
}
