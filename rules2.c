/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:35:06 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/24 02:30:43 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_struct **st_b)
{
	t_struct	*tmp;
	t_struct	*tmp1;

	if (*st_b == NULL)
		return ;
	if (count_of_nodes(*st_b) <= 1)
		return ;
	tmp = *st_b;
	*st_b = (*st_b)->link;
	tmp->link = NULL;
	tmp1 = *st_b;
	while (tmp1->link)
		tmp1 = tmp1->link;
	tmp1->link = tmp;
	ft_putstr_fd("rb\n", 1);
}

void	ft_rra(t_struct **st)
{
	t_struct	*tmp;
	t_struct	*tmp1;

	if (*st == NULL)
		return ;
	if (count_of_nodes(*st) <= 1)
		return ;
	tmp = *st;
	tmp1 = *st;
	while (tmp->link)
		tmp = tmp->link;
	while (tmp1->link->link)
		tmp1 = tmp1->link;
	tmp1->link = NULL;
	tmp->link = *st;
	*st = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_struct **st_b)
{
	t_struct	*tmp;
	t_struct	*tmp1;

	if (*st_b == NULL)
		return ;
	if (count_of_nodes(*st_b) <= 1)
		return ;
	tmp = *st_b;
	tmp1 = *st_b;
	while (tmp->link)
		tmp = tmp->link;
	while (tmp1->link->link)
		tmp1 = tmp1->link;
	tmp1->link = NULL;
	tmp->link = *st_b;
	*st_b = tmp;
	ft_putstr_fd("rrb\n", 1);
}

void	push_to_stack(t_struct **st, t_struct **st_b)
{
	t_struct	*tmp;
	t_struct	*tmp1;

	if (!*st)
		return ;
	tmp1 = *st_b;
	tmp = (*st)->link;
	*st_b = *st;
	(*st_b)->link = tmp1;
	*st = tmp;
}
