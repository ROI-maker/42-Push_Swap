/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:12:35 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/25 09:24:17 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_valid_numb_and_unique(char *num, char **list, int i, long numb)
{
	if (*num == '-' || *num == '+')
		num++;
	if (!*num)
		return (0);
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	while (list[i])
	{
		if (numb == ft_atoi(list[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_pars_args(int argc, char **argv)
{
	int			i;
	long		numb;
	char		**list;
	int			error;

	i = 0;
	error = 1;
	if (argc == 2)
		list = ft_split(argv[1], ' ');
	else
		list = argv + 1;
	if (!list || !list[0])
		error = 0;
	while (list[i] && error != 0)
	{
		numb = ft_atoi(list[i]);
		if (numb < INT_MIN || numb > INT_MAX)
			error = 0;
		if (!is_valid_numb_and_unique(list[i], list, i + 1, numb))
			error = 0;
		i++;
	}
	if (argc == 2)
		ft_free_split(list);
	return (error);
}

static t_node	*index_finder(t_node **head)
{
	t_node	*cur;
	t_node	*min;

	cur = *head;
	min = NULL;
	while (cur)
	{
		if (cur ->index == -42 && (min == NULL || (cur ->value) < (min->value)))
			min = cur;
		cur = cur->next;
	}
	return (min);
}

static void	node_indexer(t_node **head)
{
	t_node	*cur;
	int		index;

	index = 0;
	cur = index_finder(head);
	while (cur)
	{
		cur ->index = index;
		index++;
		cur = index_finder(head);
	}
}

void	ft_init_stack(t_node **head, int argc, char **argv)
{
	t_node	*new;
	char	**list;
	int		i;

	i = 0;
	if (argc == 2)
		list = ft_split(argv[1], ' ');
	else
		list = argv + 1;
	while (list[i])
	{
		new = ft_create_node(ft_atoi(list[i]));
		ft_addback(head, new);
		i++;
	}
	node_indexer(head);
	if (argc == 2)
		ft_free_split(list);
}
