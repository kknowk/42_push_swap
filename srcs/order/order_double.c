/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:10:43 by khorike           #+#    #+#             */
/*   Updated: 2023/06/30 14:18:47 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stackA, t_stack *stackB)
{
	sa(stackA);
	sb(stackB);
	ft_printf("ss\n");
}

void	rr(t_stack *stackA, t_stack *stackB)
{
	ra(stackA);
	rb(stackB);
	ft_printf("rr\n");
}

void	rrr(t_stack *stackA, t_stack *stackB)
{
	rra(stackA);
	rrb(stackB);
	ft_printf("rrr\n");
}
