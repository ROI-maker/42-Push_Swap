/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:08:27 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/25 08:45:32 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (-1);
	if (!ft_pars_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	ft_init_stack(&stack_a, argc, argv);
	if (ft_is_sorted(stack_a) || ft_list_size(stack_a) == 0)
	{
		ft_free_stack(&stack_a);
		return (0);
	}
	if (ft_list_size(stack_a) <= 20)
		ft_small_sort(&stack_a, &stack_b);
	else
		ft_chunck_sort(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
