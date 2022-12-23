/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:29:46 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/23 02:38:39 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct node
{
	int		data;
	struct node	*link;
}				t_struct;
void	make_node(t_struct **st, int data);
int	count_of_nodes(t_struct *aa);
//void	print_node(t_struct *aa);
int check_node(t_struct *st);
int ft_sa(t_struct *st);
int	ft_sb(t_struct *st_b);
void	ft_pb(t_struct **st, t_struct **st_b);
void	ft_pa(t_struct **st_b, t_struct **st);
void	ft_ra(t_struct **st);
void	ft_rb(t_struct **st_b);
void	ft_rra(t_struct **st);
void	ft_rrb(t_struct **st_b);
void	push_to_stack(t_struct **st, t_struct **st_b);
void	free_stack(t_struct **st);
void	insertion_sort(int **arr, int length);
void	array_sort(t_struct *st, int **a);
int	n_value(t_struct *st, int length);
int	index_finder(t_struct *st, int a[], int start, int end);
void	edit_start_end(int *start, int *end, int length, int offset);
int	find_where_number(int number, t_struct *st_b);
void	sort_to_stack_a(t_struct **st, t_struct **st_b, int length, int *a);
void	sort_to_stack_b(t_struct **st, t_struct **st_b, int length);
void	make_stacks(int argc, char **argv, t_struct **st);
void	error(void);
int	check_if_sorting(t_struct *st);
void	sort_three(t_struct **st);
int	ft_small_index(t_struct *st);
int	ft_small_number(t_struct *st);
void	sort_small(t_struct **st, t_struct **st_b, int length);
#endif
