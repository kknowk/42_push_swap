/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:40:37 by khorike           #+#    #+#             */
/*   Updated: 2023/07/07 17:03:06 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialize_er(t_error *er)
{
	er->er_b = 0;
	er->flag = 0;
	er->count = 0;
	er->split = 0;
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	int		*buffer3;
	t_error	er;

	initialize_er(&er);
	if (ac == 2)
	{
		av = ft_space_split(av[1], ' ', &er);
		if (!av)
			return (1);
		ac = er.count + 1;
		er.split = 1;
	}
	buffer3 = cpr_nums(ac, av, &er);
	if (!buffer3)
		return (1);
	stack_a = create_stack();
	stack_a->size = ac - 1;
	stack_a->ms = stack_a->size;
	while (--ac)
		push(stack_a, buffer3[ac - 1]);
	free(buffer3);
	six_under_or_upper(stack_a);
	return (all_free(stack_a));
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q push_swap");
// }
