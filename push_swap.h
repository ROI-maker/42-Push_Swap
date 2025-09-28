/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:58:50 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/25 08:42:08 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "includes/libft/libft.h"
# include "includes/ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

//used for the chunk_sort_boost.c file
typedef struct s_top_two
{
	int	first_index;
	int	first_pos;
	int	second_index;
	int	second_pos;
}	t_top_two;

//parsing.c
int					ft_pars_args(int argc, char **argv);
void				ft_init_stack(t_node **head, int argc, char **argv);

//utils.c
void				ft_free_split(char **split);
void				ft_free_stack(t_node **stack);

//node_utils.c
t_node				*ft_create_node(int val);
void				ft_addback(t_node **head, t_node *new);
void				ft_addfront(t_node **head, t_node *new);
int					ft_list_size(t_node *head);
void				ft_free_nodes(t_node **head);

//small_sort.c
int					ft_is_sorted(t_node *head);
void				ft_small_sort(t_node **stack_a, t_node **stack_b);

//chunk_sort.c
void				ft_chunck_sort(t_node **stack_a, t_node **stack_b);

//empty_b.c
void				empty_b(t_node **stack_a, t_node **stack_b);
void				bring_to_top(t_node **stack, int target_index);

//costs.c
int					get_first_cost(int first_pos, int second_pos, int size);
int					get_second_cost(int second_pos, int first_pos, int size);
void				push_second_then_first(t_node **stack_a,
						t_node **stack_b, t_top_two info);
void				push_first_then_second(t_node **stack_a,
						t_node **stack_b, t_top_two info);

//instructions
void				sa(t_node **stack_a, int print);
void				sb(t_node **stack_b, int print);
void				ss(t_node **stack_a, t_node **stack_b);
void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);
void				ra(t_node **stack_a, int print);
void				rb(t_node **stack_b, int print);
void				rr(t_node **stack_a, t_node **stack_b);
void				rra(t_node **stack_a, int print);
void				rrb(t_node **stack_b, int print);
void				rrr(t_node **stack_a, t_node **stack_b);

#endif
