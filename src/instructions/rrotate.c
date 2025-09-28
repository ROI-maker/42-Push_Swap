/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:48:40 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/15 16:13:48 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(t_node **stack_a, int print)
{
	t_node	*prev;
	t_node	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	prev = NULL;
	last = *stack_a;
	while (last->next)
	{
		prev = last;
		last = last ->next;
	}
	prev ->next = NULL;
	last ->next = *stack_a;
	*stack_a = last;
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_node **stack_b, int print)
{
	t_node	*prev;
	t_node	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	prev = NULL;
	last = *stack_b;
	while (last ->next)
	{
		prev = last;
		last = last ->next;
	}
	prev ->next = NULL;
	last ->next = *stack_b;
	*stack_b = last;
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_printf("rrr\n");
}
