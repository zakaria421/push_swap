/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:39:41 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/24 02:30:54 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stacks(int argc, char **argv, t_struct **st)
{
	int		j;
	char	**p;

	j = argc - 1;
	if (argc >= 2)
	{
		argc--;
		while (argc != 0)
		{
			j = 0;
			p = ft_split(argv[argc--], ' ');
			while (p[j])
				j++;
			j--;
			while (j >= 0)
			{
				make_node(&*st, ft_atoi(p[j]));
				free(p[j]);
				j--;
			}
			free(p);
		}
		if (check_node(*st) == 1)
			error();
	}
}

void	make_node(t_struct **st, int data)
{
	t_struct	*head;

	head = malloc(sizeof(t_struct));
	if (!head)
		return ;
	head->data = data;
	head->link = *st;
	*st = head;
}

int	check_node(t_struct *st)
{
	t_struct	*i;
	t_struct	*j;

	if (st == NULL)
		printf("NULL");
	i = st;
	while (i)
	{
		j = i->link;
		while (j)
		{
			if (i->data == j->data)
				return (1);
			j = j->link;
		}
		i = i->link;
	}
	return (0);
}

int	check_if_sorting(t_struct *st)
{
	while (st != NULL && st->link != NULL)
	{
		if (st->data < st->link->data)
			st = st->link;
		else
			return (0);
	}
	return (1);
}

void	error(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(1);
}
