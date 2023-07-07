/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_3_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:23:34 by khorike           #+#    #+#             */
/*   Updated: 2023/07/07 13:20:19 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	type_three(t_stack *stackA)
{
	while (!(stackA->top->data == stackA->ms - 3
			&& stackA->top->prev->data == stackA->ms - 2
			&& stackA->bottom->data == stackA->ms - 1))
	{
		if (((stackA->top->data < stackA->top->prev->data
					&& stackA->top->data < stackA->bottom->data)
				|| ((stackA->top->prev->data > stackA->bottom->data
						&& stackA->top->prev->data > stackA->top->data)
					&& (stackA->bottom->data < stackA->top->data
						&& stackA->bottom->data < stackA->top->prev->data))))
		{
			rra(stackA);
		}
		else if (((stackA->top->prev->data < stackA->bottom->data
					&& stackA->top->prev->data < stackA->top->data)
				&& (stackA->bottom->data > stackA->top->prev->data
					&& stackA->bottom->data > stackA->top->data)))
			sa(stackA);
		else if (stackA->top->data > stackA->top->prev->data
			&& stackA->top->data > stackA->bottom->data)
			ra(stackA);
	}
}

void	rev_type_three(t_stack *stackA)
{
	while (!(stackA->top->data == 2 && stackA->top->prev->data == 1
			&& stackA->bottom->data == 0))
	{
		if ((stackA->top->data == 2 || (stackA->top->data == 1
					&& stackA->bottom->data == 2)))
			rrb(stackA);
		else if ((stackA->top->data == 1 && stackA->top->prev->data == 2
				&& stackA->bottom->data == 0))
			sb(stackA);
		else if (stackA->top->data == 0)
			rb(stackA);
	}
}
