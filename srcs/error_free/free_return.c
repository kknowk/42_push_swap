/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:14:32 by khorike           #+#    #+#             */
/*   Updated: 2023/07/07 16:50:01 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*free_return(int *s1, int *s2, int *s3, t_error	*er)
{
	if ((er->er_b == 1 || er->flag == 0) && s1 && s2 && s3)
	{
		free(s1);
		free(s2);
		free(s3);
		return (0);
	}
	else if (s1 && !s2)
	{
		free(s1);
		return (0);
	}
	else if (s1 && s2 && !s3)
	{
		free(s1);
		free(s2);
		return (0);
	}
	else if (s1 && s2 && s3)
	{
		free(s1);
		free(s2);
		return (s3);
	}
	return (0);
}

int	all_free(t_stack *stack_a)
{
	t_node	*a;

	a = NULL;
	while (stack_a->top)
	{
		a = stack_a->top;
		stack_a->top = stack_a->top->prev;
		if (a)
			free(a);
	}
	free(stack_a);
	return (0);
}

void	super_free(char **s2, t_error *sp)
{
	int	i;

	i = 0;
	if (sp->split)
	{
		while (s2[i])
		{
			free(s2[i]);
			i++;
		}
		free(s2);
	}
}
