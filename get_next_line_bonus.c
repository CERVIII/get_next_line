/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:39:40 by pcervill          #+#    #+#             */
/*   Updated: 2022/05/09 16:56:01 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_write(int fd, char *save)
{
	char	*stread;
	int		sizebuff;

	sizebuff = 1;
	stread = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!stread)
		return (NULL);
	while (!ft_strchr(save, '\n') && sizebuff != 0)
	{
		sizebuff = read(fd, stread, BUFFER_SIZE);
		if (sizebuff == -1)
		{
			free(stread);
			return (NULL);
		}
		stread[sizebuff] = '\0';
		save = ft_strjoin(save, stread);
	}
	free (stread);
	return (save);
}

char	*ft_print(char *save)
{
	int		cont;
	char	*result;

	cont = 0;
	if (!save[cont])
		return (NULL);
	while (save[cont] && save[cont] != '\n')
		cont++;
	result = malloc(sizeof(char) * (cont + 2));
	if (!result)
		return (NULL);
	cont = 0;
	while (save[cont] && save[cont] != '\n' )
	{
		result[cont] = save[cont];
		cont++;
	}
	if (save[cont] == '\n')
	{
		result[cont] = '\n';
		cont++;
	}
	result[cont] = '\0';
	return (result);
}

char	*ft_cleansave(char *save)
{
	char	*newsave;
	int		cont;
	int		cont1;

	cont = 0;
	while (save[cont] && save[cont] != '\n')
		cont++;
	if (!save[cont])
	{
		free(save);
		return (NULL);
	}
	newsave = malloc(sizeof(char) * (ft_strlen(save) - cont + 1));
	if (!newsave)
		return (NULL);
	cont++;
	cont1 = 0;
	while (save[cont])
		newsave[cont1++] = save[cont++];
	newsave[cont1] = '\0';
	free(save);
	return (newsave);
}

char	*get_next_line(int fd)
{
	static char	*save[4096];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = ft_read_write(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	result = ft_print(save[fd]);
	save[fd] = ft_cleansave(save[fd]);
	return (result);
}

/*int	main(void)
{
	int		fd1;
	char	*str;

	fd1 = open("text.txt", O_RDONLY);
	str = get_next_line(fd1);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("%s\n", str);
	free(str);
	close(fd1);
	system("leaks a.out");
	return (0);
}
*/