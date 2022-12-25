/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:34:42 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/25 04:50:29 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_struct	*st;
	t_struct	*st_b;
	int			length;
	int			n;

	make_stacks(argc, &*argv, &st);
	if (check_if_sorting(st))
		return (0);
	length = count_of_nodes(st);
	n = n_value(st, length);
	if (length == 2)
		ft_sa(st);
	else if (length == 3)
		sort_three(&st);
	else if (length > 3 && length < 16)
		sort_small(&st, &st_b, length);
	else if (length >= 16)
		sort_to_stack_b(&st, &st_b, length, n);
}
