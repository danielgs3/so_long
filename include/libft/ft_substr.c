/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:34:23 by danielg3          #+#    #+#             */
/*   Updated: 2026/01/19 12:34:24 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			max_len;
	char			*sub;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	max_len = ft_strlen(s) - (start);
	if (max_len > len)
		max_len = len;
	sub = malloc ((max_len + 1) * sizeof (char));
	if (!sub)
		return (NULL);
	while (s[start] && i < max_len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
