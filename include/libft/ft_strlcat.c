/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 06:06:40 by danielg3          #+#    #+#             */
/*   Updated: 2025/05/29 19:19:58 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_length;
	unsigned int	a;
	unsigned int	dest_length;

	src_length = 0;
	a = 0;
	dest_length = 0;
	while (dest[dest_length] != '\0')
		dest_length++;
	while (src[src_length] != '\0')
		src_length++;
	if (size <= dest_length)
		return (size + src_length);
	while (a < (size - dest_length - 1) && src[a] != '\0')
	{
		dest[dest_length + a] = src[a];
		a++;
	}
	dest[dest_length + a] = '\0';
	return (dest_length + src_length);
}
