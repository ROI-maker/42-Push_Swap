/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:05:28 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/24 01:16:42 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_node *head)
{
	t_node	*cur;
	int		val;

	cur = head;
	val = cur ->value;
	while (cur)
	{
		if (val > cur ->value)
			return (0);
		val = cur->value;
		cur = cur ->next;
	}
	return (1);
}

static void	sort_3(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = *stack_a;
	second = first ->next;
	third = second ->next;
	if (first->index > second->index && first->index > third->index)
		ra(stack_a, 1);
	else if (second->index > first->index && second->index > third->index)
		rra(stack_a, 1);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, 1);
}

static void	do_ra_or_rra(t_node **stack_a, int pos, int i)
{
	if (pos <= ft_list_size(*stack_a) / 2)
	{
		while ((*stack_a)->index != i)
			ra(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->index != i)
			rra(stack_a, 1);
	}
}

static void	sort_to_20(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		pos;
	t_node	*cur;

	i = 0;
	while (ft_list_size(*stack_a) > 3)
	{
		cur = *stack_a;
		pos = 0;
		while (cur->index != i)
		{
			cur = cur->next;
			pos++;
		}
		do_ra_or_rra(stack_a, pos, i);
		pb(stack_a, stack_b);
		i++;
	}
	sort_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	ft_small_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = ft_list_size(*stack_a);
	if (size == 2)
		sa(stack_a, 1);
	else if (size == 3)
		sort_3(stack_a);
	else
		sort_to_20(stack_a, stack_b);
}
