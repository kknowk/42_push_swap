/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_stack_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:52:07 by khorike           #+#    #+#             */
/*   Updated: 2023/07/01 11:33:43 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

int	isempty(t_stack *stack)
{
	return (stack->top == NULL);
}

void	push(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	put_error_exit_node(new_node, 1);
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = stack->top;
	if (isempty(stack))
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		stack->top->next = new_node;
		new_node->prev = stack->top;
		stack->top = new_node;
	}
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		data;

	put_error_exit_stack(stack, 1);
	temp = stack->top;
	data = temp->data;
	if (stack->top == stack->bottom)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = stack->top->prev;
		stack->top->next = NULL;
	}
	free(temp);
	return (data);
}
