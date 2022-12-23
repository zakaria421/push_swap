#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

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

int	count_of_nodes(t_struct *aa)
{
	int			count;
	t_struct	*ptr;

	count = 0;
	if (aa == NULL)
		return (0);
	ptr = aa;
	while (ptr)
	{
		count++;
		ptr = ptr->link;
	}
	return (count);
}
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
	ft_putstr_fd("sa\n", 1);
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
	ft_putstr_fd("sb\n", 1);
	return (0);
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
void	ft_pb(t_struct **st, t_struct **st_b)
{
	if (!*st)
		return ;
	push_to_stack(st, st_b);
	ft_putstr_fd("pb\n", 1);
}
void	ft_pa(t_struct **st_b, t_struct **st)
{
	if (!*st_b)
		return ;
	push_to_stack(st_b, st);
	ft_putstr_fd("pa\n", 1);
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
	ft_putstr_fd("ra\n", 1);
}
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
void	insertion_sort(int **arr, int length)
{
	int i, j, key;
	i = 1;
	while (i < length)
	{
		key = (*arr)[i];
		j = i - 1;
		while (j >= 0 && (*arr)[j] > key)
		{
			(*arr)[j + 1] = (*arr)[j];
			j--;
		}
		(*arr)[j + 1] = key;
		i++;
	}
}
void	array_sort(t_struct *st, int **a)
{
	int			i;
	t_struct	*j;
	int			length;

	length = count_of_nodes(st);
	i = 0;
	j = st;
	if (!a)
	{
		free_stack(&st);
		exit(1);
	}
	while (j)
	{
		(*a)[i++] = j->data;
		j = j->link;
	}
	insertion_sort(a, length);
}
int	n_value(t_struct *st, int length)
{
	int	n;

	if (length <= 150)
		return (8);
	else
		return (18);
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
			//printf("start : %d end: %d \n",start,end);
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
void	error(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(1);
}
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
void	sort_three(t_struct **st)
{
    if(check_if_sorting(*st))
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
