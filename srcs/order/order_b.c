/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:37:25 by khorike           #+#    #+#             */
/*   Updated: 2023/07/07 15:10:29 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *stackB)
{
	int	temp;

	if (stackB->top && stackB->top->prev)
	{
		temp = stackB->top->data;
		stackB->top->data = stackB->top->prev->data;
		stackB->top->prev->data = temp;
		ft_printf("sb\n");
	}
}

void	pb(t_stack *stackA, t_stack *stackB)
{
	int	data;

	if (stackA->top)
	{
		data = pop(stackA);
		push(stackB, data);
		stackA->size--;
		stackB->size++;
		ft_printf("pb\n");
	}
}

void	rb(t_stack *stackB)
{
	t_node	*node;

	if (stackB->top && stackB->bottom != stackB->top)
	{
		node = stackB->top;
		stackB->top = stackB->top->prev;
		stackB->top->next = NULL;
		node->prev = NULL;
		stackB->bottom->prev = node;
		node->next = stackB->bottom;
		stackB->bottom = node;
		ft_printf("rb\n");
	}
}

void	rrb(t_stack *stackB)
{
	t_node	*node;

	if (stackB->bottom && stackB->bottom != stackB->top)
	{
		node = stackB->bottom;
		stackB->bottom = stackB->bottom->next;
		stackB->bottom->prev = NULL;
		node->next = NULL;
		stackB->top->next = node;
		node->prev = stackB->top;
		stackB->top = node;
		ft_printf("rrb\n");
	}
}
