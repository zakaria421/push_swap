/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bonus_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 22:45:35 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/24 23:37:15 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_struct *st)
{
	int	tmp;

	tmp = 0;
	if (st == NULL)
		return (0);
	if (count_of_nodes(st) <= 1)
		return (0);
	tmp = st->data;
	st->data = st->link->data;
	st->link->data = tmp;
	return (0);
}

int	ft_sb(t_struct *st_b)
{
	int	tmp;

	tmp = 0;
	if (st_b == NULL)
		return (0);
	if (count_of_nodes(st_b) <= 1)
		return (0);
	tmp = st_b->data;
	st_b->data = st_b->link->data;
	st_b->link->data = tmp;
	return (0);
}

void	ft_pb(t_struct **st, t_struct **st_b)
{
	if (!*st)
		return ;
	push_to_stack(st, st_b);
}

void	ft_pa(t_struct **st_b, t_struct **st)
{
	if (!*st_b)
		return ;
	push_to_stack(st_b, st);
}

void	ft_ra(t_struct **st)
{
	t_struct	*tmp;
	t_struct	*tmp1;

	if (*st == NULL)
		return ;
	if (count_of_nodes(*st) <= 1)
		return ;
	tmp = *st;
	*st = (*st)->link;
	tmp->link = NULL;
	tmp1 = *st;
	while (tmp1->link)
		tmp1 = tmp1->link;
	tmp1->link = tmp;
}
