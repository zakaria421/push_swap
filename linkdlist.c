/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkdlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:34:42 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/24 04:53:06 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_struct *aa)
{
	t_struct	*ptr;

	if (aa == NULL)
		return ;
	ptr = aa;
	while (ptr)
	{
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
}

void	free_stack(t_struct **st)
{
	t_struct	*tmp;

	tmp = (*st)->link;
	while (*st)
	{
		free(*st);
		*st = tmp;
		if (*st)
			tmp = (*st)->link;
	}
}

int	main(int argc, char *argv[])
{
	t_struct	*st;
	t_struct	*st_b;
	int			length;

	make_stacks(argc, &*argv, &st);
	if (check_if_sorting(st))
		return (0);
	length = count_of_nodes(st);
	if (length == 2)
		ft_sa(st);
	else if (length == 3)
		sort_three(&st);
	else if (length > 3 && length < 16)
	{
		sort_small(&st, &st_b, length);
	}
	else if (length >= 16)
		sort_to_stack_b(&st, &st_b, length);
	print_node(st);
	//free_stack(&st);
	//system("leaks push_swap");
}
