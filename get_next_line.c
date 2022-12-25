/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:48:28 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/24 23:37:54 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_all_line(char *a, int fd)
{
	char	*buff;
	int		i;

	i = 1;
	buff = malloc(sizeof(char) * ((BUFFER_SIZE + 1)));
	if (!buff)
		return (NULL);
	while (!ft_strchr(a, '\n') && i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			free(a);
			return (NULL);
		}
		buff[i] = '\0';
		a = ft_strjoin1(a, buff);
		if (!a)
			return (NULL);
	}
	free(buff);
	return (a);
}

char	*get_return(char *a)
{
	char	*b;
	int		i;

	i = 0;
	if (a[i] == '\0')
		return (NULL);
	while (a[i] && a[i] != '\n')
		i++;
	if (a[i] == '\0')
		b = malloc((i + 1) * sizeof(char));
	else
		b = malloc((i + 2) * sizeof(char));
	if (!b)
		return (NULL);
	i = 0;
	while (a[i] && a[i] != '\n')
	{
		b[i] = a[i];
		i++;
	}
	if (a[i] == '\n')
		b[i++] = '\n';
	b[i] = '\0';
	return (b);
}

char	*get_the_rest(char *a)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	while (a[i] && a[i] != '\n')
		i++;
	if (!a[i])
	{
		free(a);
		return (NULL);
	}
	c = malloc(((ft_strlen(a) - i) + 1) * sizeof(char));
	if (!c)
		return (NULL);
	i++;
	while (a[i])
	{
		c[j++] = a[i++];
	}
	c[j] = '\0';
	free(a);
	return (c);
}

char	*get_next_line(int fd, char **tmp)
{
	static char	*a;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	a = get_all_line(a, fd);
	if (!a)
		return (NULL);
	*tmp = get_return(a);
	a = get_the_rest(a);
	return (*tmp);
}
