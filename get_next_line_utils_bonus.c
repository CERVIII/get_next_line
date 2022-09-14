/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:40:17 by pcervill          #+#    #+#             */
/*   Updated: 2022/05/09 15:42:17 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	cont;

	cont = 0;
	while (str[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_strchr(const char *s, int c)
{
	int	cont;

	cont = 0;
	if (!s)
		return (NULL);
	while (s[cont])
	{
		if (s[cont] == (char)c)
			return ((char *)s + cont);
		cont++;
	}
	if (c == '\0')
		return ((char *)s + cont);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		cont;
	int		cont1;

	cont = -1;
	cont1 = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++cont])
		str[cont] = s1[cont];
	while (s2[++cont1])
		str[cont + cont1] = s2[cont1];
	str[cont + cont1] = '\0';
	free(s1);
	return (str);
}
