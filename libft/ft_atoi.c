/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:53:15 by zbentale          #+#    #+#             */
/*   Updated: 2022/12/23 02:56:25 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	int			result;
	static int	a;

	a = 0;
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
	if ((str[i - 1] == '-' && str[i] == 0) || (str[i - 1] == '+'
			&& str[i] == 0))
	{
		printf("ERROR2");
		exit(1);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (result > INT_MAX && sign == -1)
			return (0);
		else if (result > INT_MAX && sign == 1)
			return (-1);
		i++;
	}
	if (ft_isdigit(str[i]) == 0 && str[i] != '\0')
	{
		ft_putstr_fd("ERROR",2);
		exit(1);
	}
	return (result * sign);
}
