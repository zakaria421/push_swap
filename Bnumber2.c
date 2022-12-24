/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bnumber2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:51:00 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/24 04:53:28 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_stack_a(t_struct **st, t_struct **st_b, int length, int *a)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = length - 1;
	while (*st_b)
	{
		j = find_where_number(a[i], *st_b);
		k = 0;
		if (j <= length / 2)
		{
			while ((*st_b)->data != a[i])
			{
				if ((*st_b)->data == a[i - 1])
				{
					ft_pa(st_b, st);
					k++;
				}
				else
					ft_rb(st_b);
			}
		}
		else
		{
			while ((*st_b)->data != a[i])
			{
				if ((*st_b)->data == a[i - 1])
				{
					ft_pa(st_b, st);
					k++;
				}
				else
					ft_rrb(st_b);
			}
		}
		i--;
		ft_pa(st_b, st);
		if (k)
		{
			length--;
			ft_sa(*st);
			i--;
		}
		length--;
	}
}
