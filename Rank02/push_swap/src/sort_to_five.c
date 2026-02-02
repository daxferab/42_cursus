/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:15:04 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/24 17:22:56 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_num **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, "sa");
}

void	sort_three(t_num **stack_a)
{
	int	first;

	if (sorted(*stack_a))
		return ;
	first = first_num(*stack_a);
	if (first == 0)
	{
		rotate(stack_a, "ra");
		sort_two(stack_a);
		rev_rotate(stack_a, "rra");
	}
	else if (first == 1)
	{
		rev_rotate(stack_a, "rra");
		sort_two(stack_a);
		rev_rotate(stack_a, "rra");
	}
	else
	{
		sort_two(stack_a);
		rev_rotate(stack_a, "rra");
	}
}

void	sort_four(t_num **stack_a, t_num **stack_b)
{
	while ((*stack_a)->index != 0)
		rotate(stack_a, "ra");
	push(stack_b, stack_a, "pb");
	sort_three(stack_a);
	push(stack_a, stack_b, "pa");
}

void	sort_five(t_num **stack_a, t_num **stack_b)
{
	while ((*stack_a)->index != 0 && (*stack_a)->index != 1)
		rotate(stack_a, "ra");
	push(stack_b, stack_a, "pb");
	while ((*stack_a)->index != 0 && (*stack_a)->index != 1)
		rotate(stack_a, "ra");
	push(stack_b, stack_a, "pb");
	sort_three(stack_a);
	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
	sort_two(stack_a);
}

bool	less_than_five(t_num **stack_a, t_num **stack_b)
{
	int		size;

	size = lstsize(*stack_a);
	if (size > 5)
		return (false);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	return (true);
}
