/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kinniku.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:22:13 by khorike           #+#    #+#             */
/*   Updated: 2023/07/07 16:01:29 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_from_top(t_stack *stackA, int n)
{
	t_node	*tmp;
	int		count;

	count = 0;
	tmp = stackA->top;
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

static int	search_bottom_top(t_stack *stackA, int n)
{
	t_node	*tmp;
	int		count;

	count = 0;
	tmp = stackA->bottom;
	while (tmp)
	{
		if (tmp->data == n)
		{
			count++;
			break ;
		}
		tmp = tmp->next;
		count++;
	}
	return (count);
}

void	ra_or_rra(int num, t_stack *stackA)
{
	if ((search_from_top(stackA, num) < search_bottom_top(stackA, num)))
	{
		while (stackA->top->data != num)
		{
			ra(stackA);
		}
	}
	else
	{
		while (stackA->top->data != num)
		{
			rra(stackA);
		}
	}
}

int	search_u(t_stack *stackA, int n, int m)
{
	int		count;

	count = 0;
	while (count == 0 && n <= m)
	{
		if (stackA->top->data == n)
			return (count + 1);
		count += search_from_top(stackA, n);
		n++;
	}
	return (count);
}

void	div_three(t_stack *stackA)
{
	int		u_10_p;
	int		u_30_p;
	t_stack	*stack_b;

	stack_b = create_stack();
	stack_b->size = 0;
	while (stackA->size > 3)
	{
		u_10_p = stackA->size * 0.1 + (stackA->ms - stackA->size);
		u_30_p = stackA->size * 0.3 + (stackA->ms - stackA->size);
		if (stackA->size == 6)
			u_30_p = 2 + stackA->ms - stackA->size;
		if (stackA->size == 4)
			u_30_p = stackA->ms - stackA->size;
		vitamin(stackA, stack_b, u_30_p, u_10_p);
	}
	protein(stackA, stack_b);
	free(stack_b);
}
