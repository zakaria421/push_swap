/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:54:32 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/16 23:03:52 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			j++;
		while (s[i] && s[i] != c)
		{
			i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (j);
}

static int	ft_start(int start, int end, char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			return (i + start + end);
		}
		i++;
	}
	return (0);
}

static void	free_ptr(char **ptr, int r)
{
	while (r >= 0)
		free(ptr[--r]);
	free(ptr);
	return ;
}

static int	ft_end(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		size;
	int		r;
	int		end;
	int		start;

	if (s[0] == '\0')
	{
		ft_putendl_fd("ERROR", 2);
		exit(1);
	}
	r = 0;
	start = 0;
	end = 0;
	if (!s)
		return (0);
	size = ft_count(s, c);
	ptr = malloc(sizeof(char *) * (size + 1));
	if (!ptr)
		return (NULL);
	while (r < size)
	{
		start = ft_start(start, end, s + start + end, c);
		end = ft_end(s + start, c);
		ptr[r] = ft_substr(s, start, end);
		if (ptr[r] == NULL)
			return (free_ptr(ptr, r), NULL);
		r++;
	}
	return (ptr[r] = NULL, ptr);
}
