/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_6_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:54:00 by khorike           #+#    #+#             */
/*   Updated: 2023/07/07 16:18:07 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	six_under_or_upper(t_stack *stack_a)
{
	if (stack_a->size < 6)
		under_six(stack_a);
	if (stack_a->size >= 6)
		div_three(stack_a);
}

void	under_six(t_stack *stackA)
{
	if (stackA->size == 2)
	{
		if (stackA->top->data > stackA->bottom->data)
			sa(stackA);
		return ;
	}
	else if (stackA->size == 3)
		type_three(stackA);
	else if (stackA->size == 4)
		type_four(stackA);
	else if (stackA->size == 5)
		type_five(stackA);
}

void	type_four(t_stack *stackA)
{
	t_stack	*stack_b;
	int		i;

	i = 0;
	stack_b = create_stack();
	while (stackA->top->data <= 2)
		pb(stackA, stack_b);
	if (stackA->bottom->data != 3)
		ra(stackA);
	while (stackA->top->data <= 2)
		pb(stackA, stack_b);
	rev_type_three(stack_b);
	while (i < 3)
	{
		pa(stackA, stack_b);
		i++;
	}
	free(stack_b);
}

void	type_five(t_stack *stackA)
{
	t_stack	*stack_b;
	int		i;

	i = 0;
	stack_b = create_stack();
	while (stackA->top->data <= 2)
		pb(stackA, stack_b);
	if (stackA->top->data == 3 || stackA->top->data == 4)
		ra(stackA);
	while (stackA->top->data <= 2)
		pb(stackA, stack_b);
	if (stackA->top->data == 3 || stackA->top->data == 4)
		ra(stackA);
	while (stackA->top->data <= 2)
		pb(stackA, stack_b);
	rev_type_three(stack_b);
	if (stackA->top->data > stackA->bottom->data)
		sa(stackA);
	while (i < 3)
	{
		pa(stackA, stack_b);
		i++;
	}
	free(stack_b);
}
