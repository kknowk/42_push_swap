/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_compression.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:08:15 by khorike           #+#    #+#             */
/*   Updated: 2023/07/07 18:53:37 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_copy_int(int	*s1, char **s2, int n, t_error *sp)
{
	int	i;

	i = 0;
	if (sp->split)
	{
		while (n > 0)
		{
			s1[i] = pien_atoi(s2[i], sp);
			i++;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			s1[i] = pien_atoi(s2[i + 1], sp);
			i++;
			n--;
		}
	}
	super_free(s2, sp);
}

void	ft_copy_normal(int	*s1, int *s2, int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		s1[i] = s2[i];
		i++;
		n--;
	}
}

void	bubblesort(int *buffer, int n, t_error *er)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	while (j++ < n)
	{
		i = 0;
		while (i + 1 < n)
		{
			if (buffer[i] == buffer[i + 1])
			{
				er->er_b = 1;
				return ;
			}
			if (buffer[i] > buffer[i + 1])
			{
				tmp = buffer[i];
				buffer[i] = buffer[i + 1];
				buffer[i + 1] = tmp;
				er->flag = 1;
			}
			i++;
		}
	}
}

void	create_compression(int *s1, int *s2, int *s3, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (s1[i] != s2[j])
			j++;
		s3[i] = j;
		i++;
	}
}

int	*cpr_nums(int ac, char *av[], t_error *er)
{
	int		*buffer1;
	int		*buffer2;
	int		*buffer3;
	int		tmp;

	buffer3 = NULL;
	buffer1 = (int *)malloc((ac - 1) * sizeof(int));
	if (!buffer1)
		return (0);
	buffer2 = (int *)malloc((ac - 1) * sizeof(int));
	if (!buffer2)
		return ((free_return(buffer1, buffer2, buffer3, er)));
	buffer3 = (int *)malloc((ac - 1) * sizeof(int));
	if (!buffer3)
		return ((free_return(buffer1, buffer2, buffer3, er)));
	tmp = ac - 1;
	ft_copy_int(buffer1, av, tmp, er);
	ft_copy_normal(buffer2, buffer1, tmp);
	bubblesort(buffer1, tmp, er);
	if (er->er_b == 1 || er->flag == 0)
		return (free_return(buffer1, buffer2, buffer3, er));
	create_compression(buffer2, buffer1, buffer3, tmp);
	return ((free_return(buffer1, buffer2, buffer3, er)));
}
