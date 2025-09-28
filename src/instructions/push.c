/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:32:59 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/15 16:13:39 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (!stack_b || !*stack_b || !stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = tmp ->next;
	tmp ->next = *stack_a;
	*stack_a = tmp;
	ft_printf("pa\n");
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	tmp = *stack_a;
	*stack_a = tmp ->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	ft_printf("pb\n");
}
