/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 02:26:03 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/24 17:22:56 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

int	count_rot(t_num *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void	ksort_first(t_num **stack_a, t_num **stack_b, int len)
{
	int	i;
	int	k;

	i = 0;
	k = ft_sqrt(len) * 14 / 10;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			push(stack_b, stack_a, "pb");
			rotate(stack_b, "rb");
			i++;
		}
		else if ((*stack_a)->index <= i + k)
		{
			push(stack_b, stack_a, "pb");
			i++;
		}
		else
			rotate(stack_a, "ra");
	}
}

void	ksort_second(t_num **stack_a, t_num **stack_b, int len)
{
	int	rot_count;
	int	rrot_count;

	while (len > 0)
	{
		rot_count = count_rot(*stack_b, len - 1);
		rrot_count = (len + 3) - rot_count;
		if (rot_count <= rrot_count)
			while ((*stack_b)->index != len - 1)
				rotate(stack_b, "rb");
		else
			while ((*stack_b)->index != len - 1)
				rev_rotate(stack_b, "rrb");
		push(stack_a, stack_b, "pa");
		len--;
	}
}
