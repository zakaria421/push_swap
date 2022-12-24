/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snumber_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:37:47 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/24 02:34:05 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_struct **st)
{
	if (check_if_sorting(*st))
		return ;
	if ((*st)->data < (*st)->link->data
		&& (*st)->data < (*st)->link->link->data)
	{
		ft_rra(&*st);
		ft_sa(*st);
	}
	else if ((*st)->data > (*st)->link->data
		&& (*st)->data < (*st)->link->link->data)
		ft_sa(*st);
	else if ((*st)->data < (*st)->link->data
		&& (*st)->data > (*st)->link->link->data)
		ft_rra(&*st);
	else if ((*st)->data > (*st)->link->data
		&& (*st)->data > (*st)->link->link->data
		&& (*st)->link->data < (*st)->link->link->data)
		ft_ra(&*st);
	else
	{
		ft_sa(*st);
		ft_rra(&*st);
	}
}

int	ft_small_index(t_struct *st)
{
	int	min;
	int	j;
	int	index;

	min = st->data;
	j = 0;
	index = 0;
	while (st != NULL)
	{
		if (st->data < min)
		{
			min = st->data;
			index = j;
		}
		st = st->link;
		j++;
	}
	return (index);
}

int	ft_small_number(t_struct *st)
{
	int	min;

	min = st->data;
	while (st != NULL)
	{
		if (st->data < min)
			min = st->data;
		st = st->link;
	}
	return (min);
}

void	sort_small(t_struct **st, t_struct **st_b, int length)
{
	int	index;
	int	min;

	while (length > 3)
	{
		index = ft_small_index(*st);
		min = ft_small_number(*st);
		if (index <= length / 2)
		{
			while ((*st)->data != min)
				ft_ra(&*st);
		}
		else
		{
			while ((*st)->data != min)
				ft_rra(&*st);
		}
		ft_pb(st, st_b);
		length--;
	}
	sort_three(st);
	while (*st_b != NULL)
		ft_pa(st_b, st);
}
