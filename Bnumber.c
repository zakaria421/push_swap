/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bnumber.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 02:17:43 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/25 03:52:19 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	help_to_sort(int index, int length, t_struct **st, t_struct **st_b)
{
	int	j;

	j = index;
	while (j)
	{
		if (index <= length / 2)
		{
			ft_ra(&*st);
			j--;
		}
		else
		{
			ft_rra(&*st);
			j++;
			if (j == length)
			{
				j = 0;
				break ;
			}
		}
	}
	ft_pb(&*st, &*st_b);
	return (--length);
}

void	sort_to_stack_b(t_struct **st, t_struct **st_b, int length, int n)
{
	int	*a;
	int	start;
	int	end;
	int	index;

	a = array_sort(*st);
	start = (length / 2) - (length / n);
	end = (length / 2) + (length / n);
	n = length;
	while (*st)
	{
		while (*st)
		{
			index = index_finder(*st, a, start, end);
			if (index == length)
			{
				edit_start_end(&start, &end, n, n / n_value(*st, n));
				break ;
			}
			length = help_to_sort(index, length, st, st_b);
			if ((*st_b)->data <= a[n / 2])
				ft_rb(st_b);
		}
	}
	(sort_to_stack_a(st, st_b, n, a), free(a));
}

int	index_finder(t_struct *st, int a[], int start, int end)
{
	int			index;
	int			i;
	t_struct	*tmp;

	index = 0;
	i = 0;
	tmp = st;
	while (tmp != NULL)
	{
		i = start;
		while (i <= end)
		{
			if (tmp->data == a[i])
				break ;
			i++;
		}
		if (i <= end && tmp->data == a[i])
			break ;
		tmp = tmp->link;
		index++;
	}
	return (index);
}

void	edit_start_end(int *start, int *end, int length, int offset)
{
	(*start) -= offset;
	(*end) += offset;
	if (*start < 0)
		*start = 0;
	if (*end >= length)
		*end = length - 1;
}

int	find_where_number(int number, t_struct *st_b)
{
	t_struct	*tmp;
	int			index;

	index = 0;
	tmp = st_b;
	while (tmp != NULL)
	{
		if (tmp->data == number)
		{
			return (index);
		}
		tmp = tmp->link;
		index++;
	}
	return (index);
}
