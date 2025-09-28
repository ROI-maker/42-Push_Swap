/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 23:33:25 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/25 08:41:53 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	find_position(t_node *stack, int target_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	bring_to_top(t_node **stack, int target_index)
{
	int	pos;
	int	size;

	pos = find_position(*stack, target_index);
	size = ft_list_size(*stack);
	if (pos == -1)
		return ;
	if (pos <= size / 2)
		while ((*stack)->index != target_index)
			rb(stack, 1);
	else
		while ((*stack)->index != target_index)
			rrb(stack, 1);
}

static void	update_top_two(t_top_two *info, int index, int pos)
{
	if (index > info->first_index)
	{
		info->second_index = info->first_index;
		info->second_pos = info->first_pos;
		info->first_index = index;
		info->first_pos = pos;
	}
	else if (index > info->second_index)
	{
		info->second_index = index;
		info->second_pos = pos;
	}
}

static t_top_two	find_top_two(t_node *stack_b)
{
	t_top_two	info;
	t_node		*cur;
	int			pos;

	info.first_index = -1;
	info.second_index = -1;
	info.first_pos = -1;
	info.second_pos = -1;
	cur = stack_b;
	pos = 0;
	while (cur)
	{
		update_top_two(&info, cur->index, pos);
		cur = cur->next;
		pos++;
	}
	return (info);
}

void	empty_b(t_node **stack_a, t_node **stack_b)
{
	int			size;
	t_top_two	info;
	int			first_cost;
	int			second_cost;

	while (*stack_b)
	{
		size = ft_list_size(*stack_b);
		info = find_top_two(*stack_b);
		if (info.second_index == -1)
		{
			pa(stack_a, stack_b);
			continue ;
		}
		first_cost = get_first_cost(info.first_pos,
				info.second_pos, size);
		second_cost = get_second_cost(info.second_pos,
				info.first_pos, size);
		if (second_cost < first_cost)
			push_second_then_first(stack_a, stack_b, info);
		else
			push_first_then_second(stack_a, stack_b, info);
	}
}
