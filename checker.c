/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:52:23 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/25 04:47:11 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"



int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	action(char *tmp, t_struct **st, t_struct **st_b)
{
	if (ft_strcmp(tmp, "sa\n") == 1)
		ft_sa(*st);
	else if (ft_strcmp(tmp, "sb\n") == 1)
		ft_sb(*st_b);
	else if (ft_strcmp(tmp, "pa\n") == 1)
		ft_pa(st_b, st);
	else if (ft_strcmp(tmp, "pb\n") == 1)
		ft_pb(st, st_b);
	else if (ft_strcmp(tmp, "ra\n") == 1)
		ft_ra(st);
	else if (ft_strcmp(tmp, "rb\n") == 1)
		ft_rb(st_b);
	else if (ft_strcmp(tmp, "rra\n") == 1)
		ft_rra(st);
	else if (ft_strcmp(tmp, "rrb\n") == 1)
		ft_rrb(st_b);
	else if (ft_strcmp(tmp, "ss\n") == 1)
		ft_ss(*st, *st_b);
	else if (ft_strcmp(tmp, "rr\n") == 1)
		ft_rr(st, st_b);
	else if (ft_strcmp(tmp, "rrr\n") == 1)
		ft_rrr(st, st_b);
	else
		error();
}

int	main(int argc, char *argv[])
{
	t_struct	*st;
	t_struct	*st_b;
	char		*tmp;

	st_b = NULL;
	make_stacks(argc, &*argv, &st);
	while (get_next_line(0, &tmp) != NULL)
	{
		action(tmp, &st, &st_b);
		free(tmp);
	}
	if (check_if_sorting(st) && st_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	//system("leaks checker");
}
