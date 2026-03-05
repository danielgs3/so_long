/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:55:07 by danielg3          #+#    #+#             */
/*   Updated: 2025/06/02 13:02:43 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_res(char **res)
{
	unsigned int	i;

	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static char	**word_selector(char *s, char c, char **res, unsigned int k)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (s[i] != 0)
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j > 0)
		{
			res[k] = ft_substr(s, i, j);
			if ((!res[k]) && (j > 0))
			{
				free_res(res);
				return (NULL);
			}
		}
		if (j > 0)
			k++;
		i = i + j;
	}
	return (res[k] = NULL, res);
}

static int	word_counter(char *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	while (s[i] != 0)
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j > 0)
			k++;
		i = i + j;
	}
	return (k);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	res = malloc(((word_counter((char *)s, c)) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res = word_selector((char *)s, c, res, 0);
	if (res == NULL)
		return (free(res), NULL);
	return (res);
}

// #include <stdio.h>

// int main()
// {
// 	char *s = ft_strdup("      Trip   ouille       ");
// 	char **res;
// 	res = ft_split(s , ' ');
// 	int i = 0;
// 	while (res[i] != NULL)
// 	{
// 		printf("X%sX\n", res[i++]);
// 	}
// 	free(res[0]);
// 	free(res[1]);
// 	/* free(res[2]);
// 	free(res[3]);
// 	free(res[4]);
// 	free(res[5]);
// 	free(res[6]);
// 	free(res[7]);
// 	free(res[8]);
// 	free(res[9]); */
// 	free(res);
// 	free(s);
// 	return (0);
// }

// int main()
// {
// 	char *s = "hello!";
// 	char **res;
// 	res = ft_split(s, ' ');
// 	printf("%s\n", res[0]);
// 	printf("%s\n", res[1]);
// 	// printf("%s\n", res[2]);
// 	// printf("%s\n", res[3]);
// 	// printf("%s\n", res[4]);
// 	//printf("%s\n", res[2]);
// 	//printf("%s\n", (char *)res[3]);
// 	free(res[0]);
// 	free(res[1]);
// 	//free(res[2]);
// 	//free(res[3]);
// 	//free(res[4]);
// 	free(res);
// 	return (0);
// }

// #include <stdio.h>
// #include <stdlib.h>

// char	**ft_split(char const *s, char c); // Declaración

// int main(void)
// {
// 	char **res = ft_split("hello!", ' '); // solo una palabra
// 	if (!res)
// 	{
// 		printf("ft_split returned NULL\n");
// 		return (1);
// 	}
// 	printf("res[0]: %s\n", res[0]);
// 	printf("res[1]: %s\n", res[1]); // debería ser NULL

// 	// Liberación
// 	free(res[0]);
// 	free(res[1]); // aquí accedés a memoria que no fue reservada
// 	free(res);
// 	return (0);
// }
