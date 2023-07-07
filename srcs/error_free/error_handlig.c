/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:19:26 by khorike           #+#    #+#             */
/*   Updated: 2023/07/07 19:17:28 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_error(int type)
{
	char	*str;

	str = "Error\n";
	if (type >= 1)
	{
		write(STDERR_FILENO, str, strlen(str));
		return (1);
	}
	return (0);
}

void	put_error_exit_node(t_node	*new_node, int type)
{
	char	*str;

	str = "Error\n";
	if (type >= 1 && new_node == NULL)
	{
		write(STDERR_FILENO, str, strlen(str));
		exit (1);
	}
}

void	put_error_exit_stack(t_stack *stack, int type)
{
	char	*str;

	str = "Error\n";
	if (type >= 1 && isempty(stack))
	{
		write(STDERR_FILENO, str, strlen(str));
		exit (1);
	}
}

void	put_error_return_stack(t_stack *stack, int type)
{
	char	*str;

	str = "Error\n";
	if (type >= 1 && isempty(stack))
	{
		write(STDERR_FILENO, str, strlen(str));
		return ;
	}
}

void	digit_handle(char **str, t_error *er)
{
	int	i;
	int	j;

	i = 1;
	er->er_b = 0;
	while (str[i])
	{
		j = 0;
		while ((str[i][j] == ' ' || str[i][j] == '-' || (str[i][j] >= '0'
		&& str[i][j] <= '9'))
				&& str[i][j])
		{
			j++;
		}
		if ((str[i][j] < '0' || str[i][j] > '9') && str[i][j])
		{
			er->er_b = 1;
			return ;
		}
		i++;
	}
}
