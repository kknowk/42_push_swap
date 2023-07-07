/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nakenasino_atoi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:46:59 by khorike           #+#    #+#             */
/*   Updated: 2023/07/07 19:19:10 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	plus_atoi(const char *str, int sign, t_error *sp)
{
	size_t		i;
	long int	over_div;
	long int	over_mod;
	long int	num;

	i = 0;
	over_div = INT_MAX / 10;
	over_mod = INT_MAX % 10;
	num = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (num > over_div || (over_div == num && over_mod < str[i] - '0'))
		{
			if (sign == 1)
				return (sp->er_b = 1);
			else
				return (sp->er_b = 1);
		}
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)num);
}

int	pien_atoi(const char *str, t_error *sp)
{
	size_t	i;
	int		num;
	size_t	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	num = plus_atoi(&str[i], sign, sp);
	return (sign * num);
}
