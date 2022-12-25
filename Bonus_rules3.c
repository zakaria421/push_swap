/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bonus_rules3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 23:20:31 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/24 23:38:33 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_struct *st, t_struct *st_b)
{
	ft_sa(st);
	ft_sb(st_b);
}

void	ft_rr(t_struct **st, t_struct **st_b)
{
	ft_ra(st);
	ft_rb(st_b);
}

void	ft_rrr(t_struct **st, t_struct **st_b)
{
	ft_rra(st);
	ft_rrb(st_b);
}
