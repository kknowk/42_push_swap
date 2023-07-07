/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protein.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:12:49 by khorike           #+#    #+#             */
/*   Updated: 2023/07/07 16:02:43 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_from_top_b(t_stack *stackB, int n)
{
	t_node	*tmp;
	int		count;

	count = 0;
	tmp = stackB->top;
	while (tmp)
	{
		if (tmp->data == n)
		{
			count++;
			break ;
		}
		tmp = tmp->prev;
		count++;
	}
	return (count);
}

void	rb_or_rrb(int num, t_stack *stackB)
{
	if ((search_from_top_b(stackB, num) < stackB->size / 2))
	{
		while (stackB->top->data != num)
		{
			rb(stackB);
		}
	}
	else
	{
		while (stackB->top->data != num)
		{
			rrb(stackB);
		}
	}
}

void	protein(t_stack *stackA, t_stack *stack_b)
{
	type_three(stackA);
	while (stackA->size < stackA->ms)
	{
		rb_or_rrb(stackA->ms - stackA->size - 1, stack_b);
		pa(stackA, stack_b);
	}
}

void	vitamin(t_stack *stackA, t_stack *stack_b, int u_30_p, int u_10_p)
{
	while (search_u(stackA, stackA->ms - stackA->size, u_30_p))
	{
		if (stackA->top->data > u_30_p)
			ra(stackA);
		else if (stackA->top->data <= u_10_p)
		{
			pb(stackA, stack_b);
			rb(stack_b);
		}
		else if (stackA->top->data <= u_30_p)
			pb(stackA, stack_b);
	}
}
