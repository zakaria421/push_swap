/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sarr_and_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:48:36 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/25 03:53:56 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(int **arr, int length)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < length)
	{
		key = (*arr)[i];
		j = i - 1;
		while (j >= 0 && (*arr)[j] > key)
		{
			(*arr)[j + 1] = (*arr)[j];
			j--;
		}
		(*arr)[j + 1] = key;
		i++;
	}
}

int	*array_sort(t_struct *st)
{
	int			i;
	t_struct	*j;
	int			length;
	int			*a;

	length = count_of_nodes(st);
	i = 0;
	j = st;
	a = malloc(sizeof(int) * length);
	if (!a)
	{
		free_stack(&st);
		exit(1);
	}
	while (j)
	{
		a[i++] = j->data;
		j = j->link;
	}
	insertion_sort(&a, length);
	return (a);
}

int	count_of_nodes(t_struct *aa)
{
	int			count;
	t_struct	*ptr;

	count = 0;
	if (aa == NULL)
		return (0);
	ptr = aa;
	while (ptr)
	{
		count++;
		ptr = ptr->link;
	}
	return (count);
}
