/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:53:15 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/24 03:05:14 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error1(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	check_dig(char a)
{
	if (ft_isdigit(a) == 0 && a != '\0')
		error1();
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if ((str[i - 1] == '-' || str[i - 1] == '+') && !str[i])
		error1();
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
		if (result > INT_MAX || result < INT_MIN)
			error1();
	}
	check_dig(str[i]);
	return (result * sign);
}
