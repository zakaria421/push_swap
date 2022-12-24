/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bnumber.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 02:17:43 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/24 04:53:37 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_stack_b(t_struct **st, t_struct **st_b, int length)
{
	int	*a;
	int	n;
	int	middle;
	int	offset;
	int	start;
	int	end;
	int	index;
	int	j;
	int	i;

	a = malloc(sizeof(int) * length);
	array_sort(*st, &a);
	n = n_value(*st, length);
	middle = length / 2;
	offset = length / n;
	n = length;
	start = middle - offset;
	end = middle + offset;
	while (*st)
	{
		i = start;
		while (i <= end)
		{
			index = index_finder(*st, a, start, end);
			if (index == length)
			{
				edit_start_end(&start, &end, n, offset);
				break ;
			}
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
			length--;
			if ((*st_b)->data <= a[n / 2])
				ft_rb(st_b);
			i++;
		}
	}
	sort_to_stack_a(st, st_b, n, a);
	free(a);
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

int	n_value(t_struct *st, int length)
{
	int	n;

	if (length <= 150)
		return (8);
	else
		return (18);
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
