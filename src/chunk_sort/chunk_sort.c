/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 00:32:40 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/24 16:09:21 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push_chunk(t_node **stack_a, t_node **stack_b, int start, int end)
{
	int	pushed;

	pushed = 0;
	while (pushed < (end - start + 1) && *stack_a)
	{
		if ((*stack_a)->index >= start && (*stack_a)->index <= end)
		{
			pb(stack_a, stack_b);
			pushed++;
			if ((*stack_b)->index > (start + end) / 2)
			{
				if (*stack_a && (*stack_a)->index > end)
					rr(stack_a, stack_b);
				else
					rb(stack_b, 1);
			}
		}
		else
			ra(stack_a, 1);
	}
}

void	ft_chunck_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	chunk_count;
	int	chunk_size;
	int	start;
	int	end;

	size = ft_list_size(*stack_a);
	if (size <= 100)
		chunk_count = 5;
	else
		chunk_count = 8;
	chunk_size = size / chunk_count;
	start = 0;
	end = chunk_size - 1;
	while (start < size)
	{
		push_chunk(stack_a, stack_b, start, end);
		start = end + 1;
		end = start + chunk_size - 1;
		if (end >= size)
			end = size - 1;
	}
	empty_b(stack_a, stack_b);
}
