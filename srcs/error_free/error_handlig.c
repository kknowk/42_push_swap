/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:19:26 by khorike           #+#    #+#             */
/*   Updated: 2023/06/29 19:31:19 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_error(int type)
{
	char	*str;

	str = "Error\n";
	if (type >= 1)
		write(STDOUT_FILENO, &str, ft_strlen(str));
	exit (1);
	return (-1);
}

void	put_error_exit_node(t_node	*new_node, int type)
{
	char	*str;

	str = "Error\n";
	if (type >= 1 && new_node == NULL)
	{
		write(STDOUT_FILENO, &str, ft_strlen(str));
		exit (1);
	}
}

void	put_error_exit_stack(t_stack *stack, int type)
{
	char	*str;

	str = "Error\n";
	if (type >= 1 && isempty(stack))
	{
		write(STDOUT_FILENO, &str, ft_strlen(str));
		exit (1);
	}
}

void	put_error_return_stack(t_stack *stack, int type)
{
	char	*str;

	str = "Error\n";
	if (type >= 1 && isempty(stack))
	{
		write(STDOUT_FILENO, &str, ft_strlen(str));
		return ;
	}
}
