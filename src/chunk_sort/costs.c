/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 00:32:26 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/25 09:01:10 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_second_then_first(t_node **stack_a,
	t_node **stack_b, t_top_two info)
{
	bring_to_top(stack_b, info.second_index);
	pa(stack_a, stack_b);
	bring_to_top(stack_b, info.first_index);
	pa(stack_a, stack_b);
	sa(stack_a, 1);
}

void	push_first_then_second(t_node **stack_a,
	t_node **stack_b, t_top_two info)
{
	bring_to_top(stack_b, info.first_index);
	pa(stack_a, stack_b);
	bring_to_top(stack_b, info.second_index);
	pa(stack_a, stack_b);
}

static int	get_steps(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (size - pos);
}

int	get_first_cost(int first_pos, int second_pos, int size)
{
	int	steps;
	int	dir_is_forward;
	int	new_pos;
	int	cost_first;
	int	cost_sec;

	steps = get_steps(first_pos, size);
	cost_first = steps + 1;
	dir_is_forward = (first_pos <= size / 2);
	if (dir_is_forward)
		new_pos = (second_pos - steps + size) % size;
	else
		new_pos = (second_pos + steps) % size;
	new_pos--;
	cost_sec = get_steps(new_pos, size - 1) + 1;
	return (cost_first + cost_sec);
}

int	get_second_cost(int second_pos, int first_pos, int size)
{
	int	steps;
	int	dir_is_forward;
	int	new_pos;
	int	cost_sec;
	int	cost_first;

	steps = get_steps(second_pos, size);
	cost_sec = steps + 1;
	dir_is_forward = (second_pos <= size / 2);
	if (dir_is_forward)
		new_pos = (first_pos - steps + size) % size;
	else
		new_pos = (first_pos + steps) % size;
	new_pos--;
	cost_first = get_steps(new_pos, size - 1) + 1;
	return (cost_sec + cost_first + 1);
}
