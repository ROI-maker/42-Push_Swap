/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:51:19 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/15 16:13:44 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_node **stack_a, int print)
{
	t_node	*first;
	t_node	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first ->next;
	first ->next = NULL;
	last = *stack_a;
	while (last ->next)
		last = last ->next;
	last ->next = first;
	if (print)
		ft_printf("ra\n");
}

void	rb(t_node **stack_b, int print)
{
	t_node	*first;
	t_node	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first ->next;
	first ->next = NULL;
	last = *stack_b;
	while (last ->next)
		last = last ->next;
	last ->next = first;
	if (print)
		ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_printf("rr\n");
}
