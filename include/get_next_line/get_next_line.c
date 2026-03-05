/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:15:53 by danielg3          #+#    #+#             */
/*   Updated: 2025/09/20 18:55:47 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_till_newline(int fd, char *remainder)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free_str(&remainder));
	buffer[0] = '\0';
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			remainder = ft_strjoin(remainder, buffer);
		}
	}
	ft_free_str(&buffer);
	if (bytes == -1)
		return (ft_free_str(&remainder));
	return (remainder);
}

char	*ft_get_newline(char *remainder)
{
	int		len;
	char	*line;
	char	*newline;

	if (!remainder)
		return (NULL);
	newline = ft_strchr(remainder, '\n');
	if (newline)
		len = (newline - remainder) + 1;
	else
		len = ft_strlen(remainder);
	line = ft_substr(remainder, 0, len);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*ft_keep_remainder(char *remainder)
{
	char	*newline;
	char	*new_remainder;
	int		len;

	if (!remainder)
		return (NULL);
	newline = ft_strchr(remainder, '\n');
	if (newline == NULL)
		return (ft_free_str(&remainder));
	len = (newline - remainder) + 1;
	if (remainder[len] == '\0')
		return (ft_free_str(&remainder));
	new_remainder = ft_substr(remainder, len, ft_strlen(remainder) - len);
	if (new_remainder == NULL)
		return (ft_free_str(&remainder));
	ft_free_str(&remainder);
	return (new_remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (remainder == NULL || !ft_strchr(remainder, '\n'))
		remainder = ft_read_till_newline(fd, remainder);
	if (!remainder)
		return (NULL);
	line = ft_get_newline(remainder);
	if (!line)
		return (ft_free_str(&remainder));
	remainder = ft_keep_remainder(remainder);
	return (line);
}


// int main() {
//     int fd = open("archivo.txt", O_RDONLY);
//     if (fd == -1) {
//         perror("Error al abrir el archivo");
//         return 1;
//     }

//     char *line;
//     while ((line = get_next_line(fd)) != NULL) {
//         if (line[0] == '\0') {
//             // Línea vacía (posiblemente por un error)
//             printf("Error: línea vacía.\n");
//             break;
//         }
//         printf("Línea leída: %s", line);
//         free(line);
//     }

//     if (line == NULL) {
//         // Verificar si fue error o EOF
//         if (read(fd, NULL, 0) == 0) {
//             printf("Fin de archivo alcanzado.\n");
//         } else {
//             perror("Error al leer");
//         }
//     }

//     close(fd);
//     return 0;
// }

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		i;

	i = 1;

	//READ FROM A FILE
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error when opening the file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("linea %d: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	//

	//READ FROM STANDARD INPUT
	fd = STDIN_FILENO;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line %d: %s", i, line);
		free(line);
		i++;
	}
	(void)argv;
	//

	(void)argc;
	return (0);
}
