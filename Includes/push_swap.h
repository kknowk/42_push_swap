/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:12:37 by khorike           #+#    #+#             */
/*   Updated: 2023/07/07 16:50:13 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/gnl/get_next_line.h"

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
	int		ms;
}	t_stack;

typedef struct s_error
{
	int	er_b;
	int	flag;
	int	count;
	int	split;
}	t_error;

char	**ft_space_split(char const *s, char c, t_error *wc);

int		put_error(int type);
void	put_error_exit_node(t_node	*new_node, int type);
void	put_error_exit_stack(t_stack *stack, int type);
void	put_error_return_stack(t_stack *stack, int type);

int		*free_return(int *s1, int *s2, int *s3, t_error	*er);
int		all_free(t_stack *stack_a);
void	super_free(char **s2, t_error *sp);

t_stack	*create_stack(void);
int		isempty(t_stack *stack);
void	push(t_stack *stack, int data);
int		pop(t_stack *stack);

void	bubblesort(int *buffer, int n, t_error *er);

void	ft_copy_int(int	*s1, char **s2, int n, t_error *sp);
void	ft_copy_normal(int	*s1, int *s2, int n);
void	create_compression(int *s1, int *s2, int *s3, int n);
int		*cpr_nums(int ac, char *av[], t_error *er);

void	sa(t_stack *stackA);
void	pa(t_stack *stackA, t_stack *stackB);
void	ra(t_stack *stackA);
void	rra(t_stack *stackA);

void	sb(t_stack *stackB);
void	pb(t_stack *stackA, t_stack *stackB);
void	rb(t_stack *stack);
void	rrb(t_stack *stackB);

void	ss(t_stack *stackA, t_stack *stackB);
void	rr(t_stack *stackA, t_stack *stackB);
void	rrr(t_stack *stackA, t_stack *stackB);

void	type_three(t_stack *stackA);
void	rev_type_three(t_stack *stackA);

void	type_four(t_stack *stackA);
void	type_five(t_stack *stackA);

void	under_six(t_stack *stackA);
void	six_under_or_upper(t_stack *stack_a);

int		search_u(t_stack *stackA, int n, int m);

void	ra_or_rra(int num, t_stack *stackA);
void	rb_or_rrb(int num, t_stack *stackB);
void	protein(t_stack *stackA, t_stack *stack_b);
void	vitamin(t_stack *stackA, t_stack *stack_b, int u_30_p, int u_10_p);
void	div_three(t_stack *stackA);

#endif