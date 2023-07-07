/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:14:34 by khorike           #+#    #+#             */
/*   Updated: 2023/07/07 15:10:16 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stackA)
{
	int	temp;

	if (stackA->top && stackA->top->prev)
	{
		temp = stackA->top->data;
		stackA->top->data = stackA->top->prev->data;
		stackA->top->prev->data = temp;
		ft_printf("sa\n");
	}
}

void	pa(t_stack *stackA, t_stack *stackB)
{
	int	data;

	if (stackB->top)
	{
		data = pop(stackB);
		push(stackA, data);
		stackA->size++;
		stackB->size--;
		ft_printf("pa\n");
	}
}

void	ra(t_stack *stackA)
{
	t_node	*node;

	if (stackA->top && stackA->bottom != stackA->top)
	{
		node = stackA->top;
		stackA->top = stackA->top->prev;
		stackA->top->next = NULL;
		node->prev = NULL;
		stackA->bottom->prev = node;
		node->next = stackA->bottom;
		stackA->bottom = node;
		ft_printf("ra\n");
	}
}

void	rra(t_stack *stackA)
{
	t_node	*node;

	if (stackA->bottom && stackA->bottom != stackA->top)
	{
		node = stackA->bottom;
		stackA->bottom = stackA->bottom->next;
		stackA->bottom->prev = NULL;
		node->next = NULL;
		stackA->top->next = node;
		node->prev = stackA->top;
		stackA->top = node;
		ft_printf("rra\n");
	}
}
